#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 199309L
#endif

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

struct options
{
	int m_verbose;
	int m_numOfWrites;
	int m_secParent;
	int m_secChild;
	int m_bufferSize;
};
static void getOptions(int argc, char **argv, struct options *myopts);
static void getOptions(int argc, char **argv, struct options *myopts)
{
	int opt;

	/* default */
	myopts->m_verbose = 1;
	myopts->m_numOfWrites = 3;
	myopts->m_secParent = 1;
	myopts->m_secChild = 1;
	myopts->m_bufferSize = 1;

    while((opt = getopt(argc, argv, "vn:p:c:s:")) != -1)  
    {  
        switch(opt)  
        {  
            case 'v':
			myopts->m_verbose = 1;
			break;

            case 'n':
			myopts->m_numOfWrites = atoi(optarg);
			break;

            case 'p':
			myopts->m_secParent = atoi(optarg);  
            break;

			case 'c':
			myopts->m_secChild = atoi(optarg);  
            break;

			case 's':
			myopts->m_bufferSize = atoi(optarg);  
            break;

			default:
			printf("Bad Input\n");
			break;
        }  
    }  
}

void child(int* _P,int _verbose,int _c,int _s);
void parent(int* _P,int _N,int _p);



int main(int argc, char *argv[])
{
	struct options op;
	int p[2];
	int pid;
	int status;
	int opt;
	getOptions(argc,argv,&op);
     	
	if(pipe(p)==-1)
	{
		perror("pipe");
	}
	pid=fork();
	if(pid==-1)
	{
		perror("fork");	
		return -1;	
	}
	else if(pid==0)
	{
		/*child(p,1,1,1);*/
		child(p,op.m_verbose,op.m_secChild,op.m_bufferSize);
		return 0;
	}
	else
	{
		/*parent(p,3,1);*/
		parent(p,op.m_numOfWrites,op.m_secChild);
		waitpid(pid,&status,0);
		return 0;
	}
	return 0;
}

void child(int* _P,int _verbose,int _secChild,int _s)
{
	char *buffer;
	buffer=(char*)malloc(_s*sizeof(char));
	if(NULL==buffer)
	{
		perror("malloc");
	}
	if(close(_P[1])==-1)
	{
		perror("close");
	}
	while(read(_P[0],buffer,1)>0)
	{
		if(_verbose)
		{
			printf("%s",buffer);

		}
		usleep(_secChild);
	}
	
	if(close(_P[0])==-1)
	{
		perror("close");
	}
	free(buffer);
}

void parent(int* _P,int _numOfWrites,int _secParent)
{
	int i;
	char msg[]="This is my msg\n";

	if(close(_P[0])==-1)
	{
		perror("close");
	}
	for(i=0;i<_numOfWrites;i++)
	{
		usleep(_secParent);
		write(_P[1],msg,strlen(msg)+1);
	}
		if(close(_P[1])==-1)
	{
		perror("close");
	}		
}

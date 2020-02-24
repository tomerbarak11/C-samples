#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif

#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
 
typedef struct Options
{
	size_t m_deleteFifo;
	size_t m_createFifo;
}Options;
/***************************************************************/
static void GetOptions(int _argc, char **_argv,Options *_options);
/**************************************************************/

int main(int argc, char *argv[]) 
{ 
	Options options;
 	int fd; 
    char *myfifo = "mypipe"; 
    char arr[80]; 
	int mkfifoResult=0;

	GetOptions(argc, argv, &options);
	if(options.m_createFifo)
	{
		mkfifoResult=mkfifo(myfifo, 0666);
		if(-1==mkfifoResult)
		{
			printf("mkfifo failed\n");
		}  
		while (1) 
		{  
		    fd = open(myfifo, O_WRONLY); 
	  		fgets(arr, 80, stdin);   
		    write(fd, arr, strlen(arr)+1); 
		    close(fd);
			if(options.m_deleteFifo)
			{ 
		 		if(unlink(myfifo)!=0)
				{
					printf("unlink failed\n");
				}
				printf("unlinked\n");
			} 
		} 
	}
	return 0;
}

static void GetOptions(int _argc, char **_argv,Options *_options)
{
	int opt;
	/*default options*/
	_options->m_createFifo=1;
	_options->m_deleteFifo=0;

	while((opt=getopt(_argc,_argv,"cd")) !=-1)
	{
		switch(opt)
		{
			case 'c':
			{
				_options->m_createFifo=1;
				break;
			}
			case 'd':
			{
				_options->m_deleteFifo=1;
				break;
			}
		}
	}
	return;
}


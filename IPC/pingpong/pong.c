
#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif

#include <stdlib.h>
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

typedef struct Options
{
	char* m_fifoFileName;
	size_t m_sizeOfBuffer;
	size_t m_timeToSleep;
	size_t m_verbose;
}Options;

/***************************************************************/
static void GetOptions(int _argc, char **_argv,Options *_options);
/**************************************************************/


int main(int argc, char *argv[]) 
{ 
	int fd1,nBytes=0;
    char *buf; 
	Options options;

	GetOptions(argc, argv, &options);
	/* add one char for NUL */
	buf=(char*) calloc(options.m_sizeOfBuffer+1, sizeof(char));
	if(!buf)
	{
		fprintf(stderr, "buf allocation failed\n");
		return -1;
	}
    fd1 = open(options.m_fifoFileName,O_RDONLY); 
    while ((nBytes=read(fd1, buf, options.m_sizeOfBuffer))>0) 
    {
		if(options.m_verbose)
		{
			buf[nBytes] = 0; /* mark string with NUL */
			printf("Reader got %d='%s'\n", nBytes, buf);
		}
		usleep(options.m_timeToSleep); 
        close(fd1); 		
    } 
return 0;
}

static void GetOptions(int _argc, char **_argv,Options *_options)
{
	int opt;
	/*default options*/
	_options->m_fifoFileName="mypipe";
	_options->m_sizeOfBuffer=10;
	_options->m_timeToSleep=50000;
	_options->m_verbose=1;

	while((opt=getopt(_argc,_argv,"f:r:s:v")) !=-1)
	{
		switch(opt)
		{
			case 'f':
			{
				_options->m_fifoFileName=optarg;
				break;
			}
			case 'r':
			{
				_options->m_sizeOfBuffer=atoi(optarg);
				break;
			}
			case 's':
			{
				_options->m_timeToSleep=atoi(optarg);
				break;
			}
			case 'v':
			{
				_options->m_verbose=1;
				break;
			}
		}
	}
	return;
}


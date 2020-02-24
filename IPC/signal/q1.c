#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 199309L
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

void child_sigaction(int sig, siginfo_t * sigInfo, void* a)
{
	write(0, "I will kill my father..\n", 24);
	kill(sigInfo->si_pid, sig);
}

void sigint_handler_father(int sig)
{
	write(0, "My son killed me\n", 17);
}

int main()
{
	struct sigaction sa;
 	int pid=0;
	pid = fork();
	if(pid<0)
	{
		printf("fork failed\n");
		return errno;
	}
	else if(pid>0)
	{
		printf("I am the father\n");
		sa.sa_handler = sigint_handler_father;
		sa.sa_flags = 0;
		sigemptyset(&sa.sa_mask);

		if (sigaction(SIGINT, &sa, NULL) == -1)
		{
			perror("sigaction");
			exit(1);
		}
		printf("Father before kill\n");
		sleep(1);
		kill(pid, SIGINT);	
		printf("Father is waiting\n");		
		pause();
		printf("Father died\n");
		return 0;		
	}
	else if(pid==0)
	{
		printf("I am the son\n");
		sa.sa_sigaction = child_sigaction;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);
		if (sigaction(SIGINT, &sa, NULL) == -1)
		{
			perror("sigaction");
			exit(1);
		}
		printf("Child is waiting for sigint from father\n");
		pause();		
		return 0;
	}
	return 0;
}

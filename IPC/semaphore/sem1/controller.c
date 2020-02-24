#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif
#include <stdio.h> 
#include <sys/sem.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <unistd.h>
#define N 10
#define KEY 1
typedef struct Options
{
	int m_pause;
	int m_resume;
}Options;

void SemCreate(int* id);
void SemCreate(int* id)
{
	if(((*id=semget(KEY,1,0666|IPC_CREAT))<0))
	{
		printf("semget\n");
		perror("semget");
	}
}

void SopsCreate(struct sembuf* sops);

static void GetOptions(int _argc, char **_argv,Options *_options);
static void GetOptions(int _argc, char **_argv,Options *_options)
{

	return;
}

int main(int argc, char *argv[])
{
	int id;
	int opt;
	Options op;
	struct sembuf sops={0};
	int semval;
	GetOptions(argc, argv, &op);
	SemCreate(&id);
	op.m_pause=0;
	op.m_resume=0;
	while((opt=getopt(argc,argv,"prd")) !=-1)
	{
		switch(opt)
		{
			case 'r':
			{
				printf("resume\n");
				sops.sem_op = 1;
				if (semop(id, &sops, 1) == -1)
				{
					perror("semop");
					exit(1);
				}
				op.m_pause=1;
				break;
			}
			case 'p':
			{
				printf("pause\n");
				sops.sem_op = -1;
				if (semop(id, &sops, 1) == -1)
				{
					perror("semop");
					exit(1);
				}
				op.m_resume=1;
				break;
			}
			case 'd':
			{
				printf("destroy\n");
				if((semval=semctl(id, 0, IPC_RMID, 0))<0)
				{
					perror("sem destroy");
					exit(1);
				}
				break;
			}
		}
	}
	
	return 0;
}



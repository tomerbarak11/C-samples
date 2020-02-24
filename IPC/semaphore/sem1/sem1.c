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
union semun
{
	int m_val;
	struct semid_ds *m_buf;
	unsigned short *m_arr;
	struct seminfo *__m_buf;
};

static void SemCreate(int* id,int* semval,union semun* val);
static void SemCreate(int* id,int* semval,union semun* val)
{
	if(((*id=semget(KEY,1,0666|IPC_CREAT))<0))
	{
		printf("semget\n");
		perror("semget");
	}
	if(((*semval=semctl(*id,0,SETVAL,*val)))<0)
	{
		printf("semctl\n");
		perror("semctl");
	}
	if(((*semval=semctl(*id,0,GETVAL,*val)))<0)
	{
		printf("semctl\n");
		perror("semctl");
	}
}

/*static void SopsCreate(struct sembuf* sops);
static void SopsCreate(struct sembuf* sops)
{
	sops->sem_num=0;
	sops->sem_op=1;
	sops->sem_flg=0;	
}*/

int main()
{
	int i;
	int id=KEY;
	int semval;
	struct sembuf sops={0};
	union semun val={0};
	sops.sem_num=0;
	sops.sem_op=1;
	sops.sem_flg=0;	
	
	val.m_val=1;
	SemCreate(&id,&semval,&val);

	
	printf("semval = %d\n",semval);
	printf("\n");
		
	for(i=0;i<N;i++)
	{
		sops.sem_op = -1;
		if (semop(id, &sops, 1) == -1)
		{
			perror("semop error 1");
			exit(1);
		}
		if((semval=semctl(id, 0, GETVAL, val))<0)
		{
			perror("semctl");
			exit(1);
		}
		printf("semaphore val = %d\n", semval);

		printf("i = %d\n", i);

		sops.sem_op = 1;
		if (semop(id, &sops, 1) == -1)
		{
			perror("semop error 2");
			exit(1);
		}
		if((semval=semctl(id, 0, GETVAL, val))<0)
		{
			perror("semctl");
			exit(1);
		}
		printf("semaphore val = %d\n\n", semval);
	
		sleep(1);			
	}
	
	return 0;
}

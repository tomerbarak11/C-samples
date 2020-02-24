#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 

static void SemCreate(int* id,int* semval,union semun* val);
static void SemCreate(int* id,int* semval,union semun* val)
{
	if((*id=semget(KEY,1,0666|IPC_CREAT)<0))
	{
		printf("semget\n");
		perror("semget");
	}
	if((*semval=semctl(*id,0,SETVAL,*val))<0)
	{
		printf("semctl\n");
		perror("semctl");
	}
	if((*semval=semctl(*id,0,GETVAL,*val))<0)
	{
		printf("semctl\n");
		perror("semctl");
	}
}

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
	
	key_t key = ftok("shmfile",65);
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	char *str;
	
	val.m_val=1;
	SemCreate(&id,&semval,&val);
	
	while(1)
	{	printf("1111111111111\n");
		str = (char*) shmat(shmid,0,0);
		printf("22222222222222\n");
		printf("Ping writes string\n");
		fgets(str,200,stdin);
		printf("Data written in memory: %s\n",str);
		printf("33333333333333\n");
		shmdt(str);
		printf("444444444444444444444\n");
	}
	return 0;
} 


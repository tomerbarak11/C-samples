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
    key_t key = ftok("shmfile",65); 
  
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
  
    char *str = (char*) shmat(shmid,0,0); 
  
    printf("Pong: %s\n",str); 
      
    shmdt(str); 
    shmctl(shmid,IPC_RMID,NULL); 
     
    return 0; 
} 


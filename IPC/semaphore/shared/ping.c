
#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <sys/shm.h>
#define KEY1 1
#define KEY2 2
#define KEY3 3
#define SHARED_MEMORY_SIZE 1024
#define NUM_OF_WRITES 20
union semun
{
	int              val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	struct seminfo  *__buf;  /* Buffer for IPC_INFO */
};


/****************************************************************/
static int SemCreate(int _key,int _val);
static void WriteSomething(int _shmid);
static void ReadAndPrint(int _shmid);
static void Up(int _sem);
static void Down(int _sem);
/***************************************************************/


int main()
{
	int shmid,i=0; 
	int sem1, sem2;
	sem1=SemCreate(KEY1,0);
	sem2=SemCreate(KEY2,1);
	shmid = shmget(KEY3, SHARED_MEMORY_SIZE, 0666|IPC_CREAT);
		
	for(i=0;i<NUM_OF_WRITES;i++)
	{
		WriteSomething(shmid);
		Up(sem1);
		Down(sem2);
		ReadAndPrint(shmid);
	}

	return 0;
}

static int SemCreate(int _key,int _val)
{
	union semun val;
	int semID=semget(_key, 1, 0666 | IPC_CREAT);	
	val.val=_val;
	if(semID<0)
	{
		printf("semget failed\n");
		return -1;
	}
	if(semctl(semID, 0, SETVAL, val)<0)
	{
		printf("semctl failed\n");
		return -1;
	}
	return semID;
}

static void WriteSomething(int _shmid)
{
	char* mymemory;	
	mymemory=shmat(_shmid, (void *)0,0);
	if((char *)-1 == mymemory)
	{
		printf("shmat failed\n");
		return;
	}
	printf("Enter a message\n");
	fgets(mymemory,200,stdin);
	return;
}

static void ReadAndPrint(int _shmid)
{
	char* mymemory;	
	mymemory=shmat(_shmid, (void *)0,0);
	if((char *)-1 == mymemory)
	{
		printf("shmat failed\n");
		return;
	}
	printf("shared contents: %s\n",mymemory);
	return;
}

static void Up(int _sem)
{
	struct sembuf plus = {0,1,0};	
	if (semop(_sem,&plus,1) == -1)
	{
		printf("semop failed \n");
		return ;
	}
	return;
}

static void Down(int _sem)
{
	struct sembuf minus = {0,-1,0};
	if (semop(_sem,&minus,1) == -1)
	{
		printf("semop failed \n");
		return ;
	}
	return;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_OF_THREADS 10

void* printFunc(void* _i);
int times=0;

int main()
{
	int i;
	void* vp[NUM_OF_THREADS];
	int arr[NUM_OF_THREADS];
	pthread_t threads[NUM_OF_THREADS];
	for(i=0;i<NUM_OF_THREADS;i++)
	{
		arr[i]=i;
	}
	
	for(i=0;i<NUM_OF_THREADS;i++)
	{
		vp[i]=&arr[i];
	}
	
	for(i=0;i<NUM_OF_THREADS;i++)
	{
		pthread_create(&threads[i],NULL,printFunc,vp[i]);
	}
	
	for(i=0;i<NUM_OF_THREADS;i++)
	{
		pthread_join(threads[i], NULL);
	}
	
	printf("\n");
	return 0;
}

void* printFunc(void* _i)
{
	int j;
	for(j=0;j<100;j++)
	{
		printf("Number of thread = %d\n",*(int*)_i);
		printf("Times = %d\n",times);
		times++;
	}	
	return NULL;
}

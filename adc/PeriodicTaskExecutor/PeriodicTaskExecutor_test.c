#include "mu_test.h"/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: PeriodicTaskExecutor testing
* 						DATE: 01-08-2019 14:50:28
*******************************************************************************/

#include <assert.h>
#include "PeriodicTaskExecutor.h"
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "task.h"
#define SIZE 4
static int smt(void* _item);
/*static int printHeap(const void* _item, void* context);*/
static int printNext(const void* _item, void* context);
static int pauseFunction(void* _context);
static int smt(void* _item)
{
	printf("Test item = %d\n\n",*(int*)_item);
	return 1;
}

static int pauseFunction(void* _context)
{
	PeriodicExecutorPause(_context);
	return 0;
}

/*static int printHeap(const void* _item, void* context)
{
	if(_item!=NULL)
	{
		printf("item = %d\n",*(int*)_item);
	}
	return 0;
}*/

static int printNext(const void* _item, void* context)
{
	size_t temp;
	if(_item!=NULL)
	{
		temp=getNextTime((Task*)_item);
		printf("Next time of item number %d = %ld\n",*(int*)context,temp);
		return 1;
	}
	return 0;
}

UNIT(PeriodicExecutorCreateTest)
	long hour,minute,second;
	PeriodicExecutor* ex=NULL;

	int i;
	taskFunction tf=smt;
	size_t periodArr[4]={10,13,5,8};
	size_t numberOfExecutions;
	size_t numOfTasks;
	struct timespec tp;
	ActionFunction _action=printNext;
	clock_gettime(CLOCK_REALTIME,&tp);
	second=tp.tv_sec%60;
	minute=(tp.tv_sec%3600)/60;
	hour=(((tp.tv_sec/3600)%24)+3)%24;
	/*day=tp.tv_sec/86400;*/
	printf("Current hour is %lu:%lu:%lu\n",hour,minute,second);
	ex=PeriodicExecutorCreate(CLOCK_MONOTONIC);
	for(i=0;i<SIZE;i++)
	{
		PeriodicExecutorAdd(ex,tf,&i,periodArr[i]);
	}
	printf("\n");
	numOfTasks=HeapForEach(getHeap(ex), _action, NULL);
	printf("Number of tasks = %ld\n",numOfTasks);
	printf("\n");
	numberOfExecutions= PeriodicExecutorRun(ex);	
	printf("Number of executions = %ld\n",numberOfExecutions);
END_UNIT

UNIT(PeriodicExecutorPauseTest)
	long hour,minute,second;
	PeriodicExecutor* ex=NULL;

	int i=0;
	taskFunction tf=smt;
	size_t periodArr[4]={10,13,5,8};
	size_t numberOfExecutions;
	size_t numOfTasks;
	struct timespec tp;
	ActionFunction _action=printNext;
	clock_gettime(CLOCK_REALTIME,&tp);
	second=tp.tv_sec%60;
	minute=(tp.tv_sec%3600)/60;
	hour=(((tp.tv_sec/3600)%24)+3)%24;
	/*day=tp.tv_sec/86400;*/
	printf("Current hour is %lu:%lu:%lu\n",hour,minute,second);
	ex=PeriodicExecutorCreate(CLOCK_MONOTONIC);
	PeriodicExecutorAdd(ex,tf,&i,periodArr[i]);
	i++;
	PeriodicExecutorAdd(ex,pauseFunction,ex,periodArr[i]);	
	i++;
	PeriodicExecutorAdd(ex,tf,&i,periodArr[i]);
	i++;
	PeriodicExecutorAdd(ex,tf,&i,periodArr[i]);
	printf("\n");
	numOfTasks=HeapForEach(getHeap(ex), _action, NULL);
	printf("Number of tasks = %ld\n",numOfTasks);
	printf("\n");
	numberOfExecutions= PeriodicExecutorRun(ex);	
	printf("Number of executions = %ld\n",numberOfExecutions);
END_UNIT

UNIT(PeriodicExecutorDestroyTest)
	long hour,minute,second;
	PeriodicExecutor* ex=NULL;

	int i;
	taskFunction tf=smt;
	size_t periodArr[4]={10,13,5,8};
	size_t numberOfExecutions;
	size_t numOfTasks;
	struct timespec tp;
	ActionFunction _action=printNext;
	clock_gettime(CLOCK_REALTIME,&tp);
	second=tp.tv_sec%60;
	minute=(tp.tv_sec%3600)/60;
	hour=(((tp.tv_sec/3600)%24)+3)%24;
	/*day=tp.tv_sec/86400;*/
	printf("Current hour is %lu:%lu:%lu\n",hour,minute,second);
	ex=PeriodicExecutorCreate(CLOCK_MONOTONIC);
	for(i=0;i<SIZE;i++)
	{
		PeriodicExecutorAdd(ex,tf,&i,periodArr[i]);
	}
	printf("\n");
	numOfTasks=HeapForEach(getHeap(ex), _action, NULL);
	printf("Number of tasks = %ld\n",numOfTasks);
	printf("\n");
	numberOfExecutions= PeriodicExecutorRun(ex);	
	printf("Number of executions = %ld\n",numberOfExecutions);
	PeriodicExecutorDestroy(ex);
	ASSERT_THAT(ex==NULL);
END_UNIT

TEST_SUITE(Dynamic Vector Module Unit Test)
	TEST(PeriodicExecutorCreateTest)
/*	TEST(PeriodicExecutorPauseTest)*/
	/*TEST(PeriodicExecutorDestroyTest)*/
END_SUITE


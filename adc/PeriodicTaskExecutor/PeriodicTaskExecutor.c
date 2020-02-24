/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: PeriodicTaskExecutor code
* 						DATE: 01-08-2019 14:50:28
*******************************************************************************/

#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include "PeriodicTaskExecutor.h"
#include "heap.h"
#include "vectorGeneric.h"
#include "time.h"
#include "task.h"
#include "myTime.h"
#define MAGIC_NUMBER 0xBEEFBEEF
#define DEAD_MAGIC_NUMBER 0xDEADBEEF
struct PeriodicExecutor
{
	size_t m_magicNumber;
	Heap* m_heap;
	clockid_t m_clk_id;
	int m_isRunning;
};
static int compareTaskTime(const void* _a,const void* _b);
static int compareTaskTime(const void* _a,const void* _b)
{
	size_t time1,time2;
	time1=getNextTime((Task*)_a);
	time2=getNextTime((Task*)_b);	
	/*printf("time1 = %ld\n",time1);
	printf("time2 = %ld\n",time2);*/
	if(time1<=time2)
	{
		return 1;
	}
	else if(time1==time2)
	{
		return 0;
	}
	return -1;
	
}

PeriodicExecutor* PeriodicExecutorCreate(clockid_t _clk_id)
{
	PeriodicExecutor* ex;
	LessThanComparator pfLess;
	Vector* vec;
	ex=(PeriodicExecutor*)malloc(1*sizeof(PeriodicExecutor));
	if(NULL==ex)
	{
		return NULL;
	}
	ex->m_magicNumber=MAGIC_NUMBER;
	ex->m_clk_id=_clk_id;
	vec=VectorCreate(0,1);
	pfLess=compareTaskTime;
	ex->m_heap=HeapBuild(vec,pfLess);
	ex->m_isRunning=0;
	if(NULL==ex->m_heap)
	{
		printf("NULL heap\n");
		return NULL;
	}
	return ex;
}

void PeriodicExecutorDestroy(PeriodicExecutor* _executor)
{

	if(_executor->m_magicNumber!=MAGIC_NUMBER)
	{
		return;
	}
	_executor->m_magicNumber=DEAD_MAGIC_NUMBER;
	HeapDestroy(&(_executor->m_heap));
		_executor=NULL;

	free(_executor->m_heap);
		_executor=NULL;
	free(_executor);
	_executor=NULL;
}

int PeriodicExecutorAdd
(PeriodicExecutor* _executor,int(*_taskFunction)(void*),void* _context,size_t _period_ms)
{
	HeapResultCode msg;
	Task* task;
	if(_executor->m_magicNumber!=MAGIC_NUMBER)
	{
		return -1;
	}

	task=TaskCreate(_taskFunction,_context,_period_ms);
	if(NULL==_executor->m_heap)
	{
		printf("NULL heap\n");
		return -1;		
	}
	msg=HeapInsert(_executor->m_heap,task);
	if(msg==HEAP_NOT_INITIALIZED)
	{
		printf("size = 0\n");
		return -1;
	}
	return 1;
}

size_t PeriodicExecutorRun(PeriodicExecutor* _executor)
{
	struct timespec tp;

	int tasksRan=0;
	void* min;

	if(_executor->m_magicNumber!=MAGIC_NUMBER)
	{
		return -1;
	}
	clock_gettime(_executor->m_clk_id,&tp);
	_executor->m_isRunning=1;
	while(1)
	{
		if(	_executor->m_isRunning==1)
		{
			printf("#######################Tasks running number %d#####################\n",tasksRan);

			clock_gettime(CLOCK_REALTIME,&tp);
			printHour(tp);

			printf("extracting\n");
			min=HeapExtract(_executor->m_heap);
			printf("extracted min\n");	
			if(NULL==min)
			{
				printf("Empty heap\n");
				exit(1);
			}
			TaskRun((Task*)min);
			printf("After run\n");	
			HeapInsert(_executor->m_heap,min);
			printf("Inserted\n");
			printf("\n");
			tasksRan++;
		}
	}
	return tasksRan;
}

Heap* getHeap(PeriodicExecutor* _executor)
{
	return _executor->m_heap;
}

size_t PeriodicExecutorPause(PeriodicExecutor* _executor)
{
	size_t heapSize=HeapSize(_executor->m_heap);
	_executor->m_isRunning=0;
	return heapSize;
}

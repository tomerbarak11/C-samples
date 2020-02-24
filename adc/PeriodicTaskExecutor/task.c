/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: task code
* 						DATE: 01-08-2019 16:10:42
*******************************************************************************/

#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include "task.h"
#include "PeriodicTaskExecutor.h"
#include <sys/types.h>
#include <unistd.h>
struct Task
{
	size_t m_periodTime;
	size_t m_nextTimeToRun;
	taskFunction m_tf;
	void* m_context;
	int m_pid;	
};

Task* TaskCreate(int(*_taskFunction)(void*),void* _context,size_t _period_ms)
{
	Task* task;
	task=(Task*)malloc(1*sizeof(Task));
	if(NULL==task)
	{
		return NULL;
	}
	task->m_tf=_taskFunction;
	task->m_context=_context;
	task->m_periodTime=_period_ms;
	task->m_nextTimeToRun=_period_ms;
	task->m_pid=getpid();
	return task;	
}

size_t getNextTime(Task* _item)
{
	return _item->m_nextTimeToRun;
}

void TaskRun(Task* _min)
{
	if(NULL!=_min)
	{
		printf("m_periodTime = %ld\n",_min->m_periodTime);
		printf("min next = %ld\n",_min->m_nextTimeToRun);
		_min->m_tf(_min->m_context);
		sleep(_min->m_periodTime/4);
		printf("After task function\n");
		_min->m_nextTimeToRun=_min->m_nextTimeToRun+_min->m_periodTime;
		printf("min next = %ld\n",_min->m_nextTimeToRun);
	}
}


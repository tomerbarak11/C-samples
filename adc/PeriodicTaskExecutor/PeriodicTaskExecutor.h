/**************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: PeriodicTaskExecutor header
* 						DATE: 01-08-2019 14:50:28
*******************************************************************************/

#ifndef __PERIODICTASKEXECUTOR_H__
#define __PERIODICTASKEXECUTOR_H__
#include "heap.h"
/**@Description:
 * Average time complexity :
 * Worst : 
 * @params _x :
 * @returns:
 */
typedef struct PeriodicExecutor PeriodicExecutor;
typedef  int (*taskFunction)(void* _item);
PeriodicExecutor* PeriodicExecutorCreate(clockid_t _clk_id);
void PeriodicExecutorDestroy(PeriodicExecutor* _executor);

int PeriodicExecutorAdd(PeriodicExecutor* _executor,int(*_taskFunction)(void*),void* _context,size_t _period_ms);
size_t PeriodicExecutorRun(PeriodicExecutor* _executor);
Heap* getHeap(PeriodicExecutor* _executor);
size_t PeriodicExecutorPause(PeriodicExecutor* _executor);

#endif          /* PeriodicTaskExecutor s*/





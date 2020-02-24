/**************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: task header
* 						DATE: 01-08-2019 16:10:42
*******************************************************************************/

#ifndef __TASK_H__
#define __TASK_H__

/**@Description:
 * Average time complexity :
 * Worst : 
 * @params _x :
 * @returns:
 */
typedef struct Task Task;
Task* TaskCreate(int(*_taskFunction)(void*),void* _context,size_t _period_ms);
size_t getNextTime(Task* _item);
void TaskRun(Task* min);
#endif          /* task s*/





/*******************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: queue header
* 						DATE: 27-06-2019 14:43
*******************************************************************************/

#ifndef _queue_h_
#define _queue_h_
#include "ADTDefs.h"
#include "mu_test.h"
typedef struct Queue queue;

queue* queueCreate(size_t _capacity);
/**@Description: Create a Dynamic queue of a specific size according to user input.
 * Average time complexity : 0(1).
 * @params __initialSize : initial size of the vector (number of elements capacity).
 * @params _extensionBblockSize : resizing value. 
 * can be 0 (but growth on demand will be impossible.)
 * @returns: handle to the Vector on success.
 * Null if allocation failed or if the two params are equals to 0.*/

void queueDestroy(queue* _q);

int queueIsEmpty(const *_q);

int queueIsFull(const *_q);

ADTErr enqueue(queue* _q,int _item);

ADTErr dequeue(queue* _q,int *_item);

void printQueue(const *_q);

int size(queue *pt);

int front(queue *pt);
#endif








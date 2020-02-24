/*******************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: queue header
* 						DATE: 27-06-2019 14:43
*******************************************************************************/

#ifndef _queue_h_
#define _queue_h_
#include <stdio.h>
#include <stdlib.h>
#include "ADTDefs.h"

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
/*@Description: Destroys the queue.
 * Average time complexity : 0(1).
 * @params ___q : queue*/

int queueIsEmpty(const *_q);
/**@Description: checks if the queue is empty
 * Average time complexity : 0(1).
 * @params ___q : queue
 * @returns: 1 if the queue is empty and 0 if it is full*/

int queueIsFull(const *_q);
/**@Description: checks if the queue is full
 * Average time complexity : 0(1).
 * @params ___q : queue
 * @returns: 1 if the queue is full and 0 if it is full*/

ADTErr enqueue(queue* _q,int _item);
/*@Description: enters an item to the queue
 * Average time complexity : 0(1).
 * @params ___q : queue
 * @params ___item : item to insert
 * @returns: overflaw when the queue is full and errok when there is place*/

ADTErr dequeue(queue* _q,int *_item);
/*@Description: enters an item to the queue
 * Average time complexity : 0(1).
 * @params ___q : queue
 * @params ___item : item to insert
 * @returns: overflaw when the queue is full and errok when there is place*/

int size(queue *_q);
/*@Description: returns queues size
 * Average time complexity : 0(1).
 * @params ___q : queue
 * @returns: returns queues size*/

int front(queue *_q);
/*@Description: returns head item
 * Average time complexity : 0(1).
 * @params ___q : queue
 * @returns: returns head item*/
#endif




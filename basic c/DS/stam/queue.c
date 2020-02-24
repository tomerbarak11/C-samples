/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: queue code
* 						DATE: 27-06-2019 14:57:43
*******************************************************************************/

#include <assert.h> 	    /* assert                                       */
#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include "queue.h"


struct Queue{
	size_t m_capacity;
	size_t m_head;
	size_t m_tail;
	size_t m_size;
	int *m_items;
};

queue* queueCreate(size_t _capacity)
{
	queue *q = NULL;
	q = (queue*)malloc(1*sizeof(queue));
	if(NULL==q)
	{
		printf("allocation fail\n");
	}
	q->m_items = (int*)malloc(_capacity * sizeof(int));
	if(NULL==q->m_items)
	{
		free(q);
		printf("allocation fail\n");
	}
	q->m_capacity = _capacity;
	q->m_head = 0;
 	q->m_tail = -1;
	q->m_size = 0;

	return q;
}
void queueDestroy(queue* _q)
{
	free(_q->m_items);
	free(_q);
}
int queueIsEmpty(const *_q)
{
	return !size(_q);

}
int queueIsFull(const *_q)
{
	return size(_q);

}
ADTErr enqueue(queue* _q,int _item)
{
	if (size(_q) == _q->m_capacity)
	{
		printf("OverFlow, queue is full\n");
		exit(EXIT_FAILURE);
	}

	printf("Inserting %d ", _item);

	_q->m_tail = (_q->m_tail + 1) % _q->m_capacity;
	_q->m_items[_q->m_tail] = _item;
	_q->m_size++;

	printf("head = %d, tail = %d\n", _q->m_head, _q->m_tail);
return ERR_OK;


}
ADTErr dequeue(queue* _q,int *_item)
{
		if (queueIsEmpty(_q))
	{
		printf("queue is empty\n");
		return ERR_NOT_INITIALIZED;
	}
	*_item=front(_q);
	printf("removing %lu\n", front(_q));
	
	_q->m_head = (_q->m_head + 1) % _q->m_capacity;
	_q->m_size--;
	printf("m_head = %lu, m_tail = %lu\n", _q->m_head, _q->m_tail);
	return ERR_OK;
}

int size(queue *_q)
{
	return _q->m_size;
}

int front(queue *_q)
{
	if (queueIsEmpty(_q))
	{
		printf("UnderFlow\nProgram Terminated\n");
		exit(EXIT_FAILURE);
	}

	return _q->m_items[_q->m_head];
}

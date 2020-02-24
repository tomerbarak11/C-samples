/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: queue code
* 						DATE: 27-06-2019 14:57:43
*******************************************************************************/

#include <assert.h> 	    /* assert                                       */
#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include "GenericQueue.h"


struct Queue{
	size_t m_capacity;
	size_t m_head;
	size_t m_tail;
	size_t m_size;
	void** m_items;
	int magicNumber;
};
int getMagicNumber(Queue* _q)
{
	return _q->magicNumber;
}
Queue* QueueCreate(size_t _capacity)
{
	Queue *q = NULL;
	q = (Queue*)malloc(1*sizeof(Queue));
	if(NULL==q)
	{
		printf("allocation fail\n");
	}
	q->m_items = (void**)malloc(_capacity * sizeof(void*));
	if(NULL==q->m_items)
	{
		free(q);
		printf("allocation fail\n");
	}
	q->m_capacity = _capacity;
	q->m_head = 0;
 	q->m_tail = -1;
	q->m_size = 0;
	q->magicNumber=123456789;
	return q;
}
void QueueDestroy(Queue** _q, void (*_elementDestroy)(void* _item))
{
	int i;
	if(NULL==_q||NULL==*_q)
	{
		return;
	}
	if((*_q)->magicNumber==123456789)
	{
		(*_q)->magicNumber=0;
		free((*_q)->m_items);
		free(*_q);
	}
	
	if((*_q)->m_head < (*_q)->m_tail)
	{
		for(i=(*_q)->m_head;i<(*_q)->m_tail;i++)
		{
			_elementDestroy((*_q)->m_items[i]);
		}
	}
	else
	{
		for(i=(*_q)->m_head;i<(*_q)->m_capacity;i++)
		{
			_elementDestroy((*_q)->m_items[i]);
		}
		
		for(i=0;i<(*_q)->m_tail;i++)
		{
			_elementDestroy((*_q)->m_items[i]);
		}
		
	}
	return;
}

void destroyOneElement(void* _item)
{
	free(_item);
}

int QueueIsEmpty(const Queue* _q)
{

	if(_q->magicNumber==123456789)
	{
		if(_q->m_size==0)
		{
			return 1;
		}
	}
	return 0;
}
int QueueIsFull(const Queue *_q)
{
	if(_q->magicNumber==123456789)
	{
		if(_q->m_size==_q->m_capacity)
		{
			return 1;
		}
	}
	return 0;
}
Queue_Result QueueEnqueue(Queue* _q, void* _item)
{
	if(_q->magicNumber==123456789)
	{
		if (_q->m_size == _q->m_capacity)
		{
			printf("OverFlow\nProgram Terminated\n");
			exit(EXIT_FAILURE);
		}

		printf("Inserting %d ", *(int*)_item);

		_q->m_tail = (_q->m_tail + 1) % _q->m_capacity;
		_q->m_items[_q->m_tail] = _item;
		_q->m_size++;

		printf("head = %ld, tail = %ld\n", _q->m_head, _q->m_tail);
		return QUEUE_SUCCESS;
	}
	
	return QUEUE_MAGICNUMBER;
}

Queue_Result QueueDequeue(Queue* _q, void** _pValue)
{
	if(_q->magicNumber==123456789)
	{	
		if (QueueIsEmpty(_q))
		{
			printf("queue is empty\n");
			return QUEUE_UNINITIALIZED_ERROR;
		}
		*_pValue=_q->m_items[_q->m_head];
		printf("removing %lu\n", _q->m_head);
		
		_q->m_head = (_q->m_head + 1) % _q->m_capacity;
		_q->m_size--;
		printf("m_head = %lu, m_tail = %lu\n", _q->m_head, _q->m_tail);
		return QUEUE_SUCCESS;
	}
	return QUEUE_MAGICNUMBER;
}

void printQueue(const Queue *_q)
{		
}

int size(Queue *_q)
{
	if(_q->magicNumber==123456789)
	{
		return _q->m_size;
	}
	return -1;
}

size_t QueueForEach(const Queue* _q, QueueElementAction _action, void* _context)
{
	if(_q->magicNumber==123456789)
	{
		int i=0;
		if(NULL== _q)
		{
			return 0;
		}
		for (i=0;i<_q->m_size;i++)
		{
			if(_action(_q->m_items[i],i,_context)==0)
			{
				return ++i;
			}
		}
		return i;
	}
	return 0;
}

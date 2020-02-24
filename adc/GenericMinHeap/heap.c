/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: heap code
* 						DATE: 10-07-2019 17:40:03
*******************************************************************************/

#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include "heap.h"

struct Heap
{
	Vector* m_vec;
	size_t m_heapSize;
	LessThanComparator fp;
	int m_magicNumber;
};

static Vector* minHeapify (Vector* _vec,int _i,LessThanComparator _pfLess);
static void swap(Vector* _vec,int index1,int index2);
static void* minValueOf2(void* _a,void* _b,LessThanComparator _pfLess);
static void* minValueOf3(void* _a,void* _b,void* _c,LessThanComparator _pfLess);
static void BubbleUp (Vector* _vec,int _i);
static int IsDataFound (Heap* _heap,void* _data);

Heap* HeapBuild(Vector* _vec, LessThanComparator _pfLess)
{
	int i;
	int numOfItems;
	Heap* h;
	h=(Heap*)malloc(1*sizeof(Heap));
	if(NULL==h||NULL==_vec)
	{
		printf("allocation fail\n");
		return NULL;
	}

	if(0==VectorCapacity(_vec))
	{
		printf("error\n");
	}
	numOfItems=VectorCapacity(_vec);
	for(i=numOfItems/2-1;i>=0;i--)
	{
		_vec=minHeapify(_vec,i,_pfLess);
	}
	h->m_heapSize=VectorCapacity(_vec);
	h->m_vec=_vec;
	h->m_magicNumber=123456789;
	return h;
}

static Vector* minHeapify (Vector* _vec,int _i,LessThanComparator _pfLess)
{
	void* father,*right,*left,*min;
	if(NULL==_vec)
	{
		return NULL;
	}
	VectorGet(_vec,_i,&father);
	VectorGet(_vec,2*_i+1,&left);
	VectorGet(_vec,2*_i+2,&right);	
	min= minValueOf3(father,left,right,_pfLess);
	
	if(min==left)
	{
		swap(_vec,2*_i+1,_i);
	}

	if(min==right)
	{
		swap(_vec,2*_i+2,_i);
	}
	return _vec;
}

static void* minValueOf2(void* _a,void* _b,LessThanComparator _pfLess)
{
	if(_pfLess(_a,_b)==1)
	{	
		return _a;
	} 
	else
	{
		return _b;
	}
}

static void* minValueOf3(void* _a,void* _b,void* _c,LessThanComparator _pfLess)
{
	if(_pfLess(_a,_b)==1&&_pfLess(_a,_c)==1)
	{	
		return _a;
	} 
	else if(_pfLess(_b,_a)==1&&_pfLess(_b,_c)==1)
	{
		return _b;
	}
	else
	{
		return _c;
	}
}

static void swap(Vector* _vec,int i,int j)
{
	void *index1value,*index2value;
	VectorGet(_vec,i,&index1value);
	VectorGet(_vec,j,&index2value);
	VectorSet(_vec,i,index2value);
	VectorSet(_vec,j,index1value);
	return;
}

Vector* HeapDestroy(Heap** _heap)
{
	if((*_heap)->m_magicNumber==123456789)
	{
		(*_heap)->m_magicNumber=0;
		(*_heap)->m_heapSize=0;
		free(*_heap);
	}
	return NULL;
}

HeapResultCode HeapInsert(Heap* _heap, void* _element)
{
	int numOfItem;
	if(	_heap->m_magicNumber==123456789)
	{
		if(NULL==_heap)
		{
			return HEAP_NOT_INITIALIZED;
		}
		
		VectorAppend(_heap->m_vec,_element);
		HeapSize(_heap);
		BubbleUp(_heap->m_vec,numOfItem);
		return HEAP_SUCCESS;
	}
	return HEAP_SUCCESS;
}

static void BubbleUp (Vector* _vec,int _i)
{
	void *father,*son;
	while (_i/2>0)
	{
		printf("i/2-1 = %d\n",_i/2-1);
		printf("i-1 = %d\n",_i-1);
		VectorGet(_vec,_i/2-1,&father);
		VectorGet(_vec,_i-1,&son);
		if(son<father)
		{
			VectorGet(_vec,_i/2-1,&father);
			VectorGet(_vec,_i-1,&son);
			VectorSet(_vec,_i-1,father);
			VectorSet(_vec,_i/2-1,son);
		}
		else 
		{
			return;
		}
		_i=_i/2;
	}
return;
}

const void* HeapPeek(const Heap* _heap)
{
	if(	_heap->m_magicNumber==123456789)
	{
		void* data;
		if(NULL==_heap)
		{
			return NULL;
		}
		VectorGet(_heap->m_vec, 0, &data);
		return data;
	}
	return NULL;
}

void* HeapExtract(Heap* _heap)
{
	int i;
	void* data;
	void* min;
	if(	_heap->m_magicNumber==123456789)
	{
		if(NULL==_heap)
		{
			return NULL;
		}
		VectorGet(_heap->m_vec, 0, min);
		swap(_heap->m_vec,0,HeapSize(_heap)-1);
		_heap->m_heapSize--;
		VectorRemove(_heap->m_vec,data);
		
		for(i=(_heap->m_heapSize)/2-2;i>=0;i--)
		{
			_heap->m_vec=minHeapify(_heap->m_vec,i,_heap->fp);
		}
		return min;
	}
	return NULL;
}

size_t HeapSize(const Heap* _heap)
{
	if(	_heap->m_magicNumber==123456789)
	{
		return _heap->m_heapSize;
	}
	return 0;
}

/*void HeapPrint(Heap* _heap)
{
	
	if(NULL==_heap)
	{
		return;
	}
	VectorPrint(_heap->m_vec);
}*/

void HeapSort(Vector* _vec, LessThanComparator _pfLess)
{
/*	int i,j;
	for(i=_heap->m_heapSize-1;i>=0;i--)
	{	printf("i = %d\n",i);
		swap(_heap->m_vec,0,i);
		for(j=_heap->m_heapSize/2-1;j>=0;j--)
		{
			_heap->m_vec=minHeapify(_heap->m_vec,j);
		}
	}*/
}

size_t HeapForEach(const Heap* _heap, ActionFunction _action, void* _context)
{
	void* item;
	if(_heap->m_magicNumber==123456789)
	{
		int i=0;
		if(NULL== _heap->m_vec)
		{
			return 0;
		}
		for (i=0;i<_heap->m_heapSize;i++)
		{
			VectorGet(_heap->m_vec,i,&item);
			if(_action(item,NULL)==0)
			{
				return ++i;
			}
		}
		return i;
	}
	return 0;
}

static int IsDataFound (Heap* _heap,void* _data)
{
	int i;
	void* value;
	
	for(i=0;i<_heap->m_heapSize;i++)
	{
		VectorGet(_heap->m_vec,i,&value);
		if(*(int*)value==*(int*)_data)
		{
			return 1;
		}
	}
	return 0;
}


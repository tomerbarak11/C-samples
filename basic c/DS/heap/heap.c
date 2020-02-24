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
};

static Vector* maxHeapify(Vector* _vec,int _i);
static void swap(Vector* _vec,int index1,int index2);
static int maxValue(int _a,int _b,int _c);
static void BubbleUp (Vector* _vec,int _i);
static int IsDataFound (Heap* _heap,int _data);
Heap* HeapBuild(Vector* _vec)
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

	if(ERR_OK!=VectorItemsNum(_vec,&numOfItems))
	{
		printf("error\n");
	}
	h->m_heapSize=numOfItems;
	for(i=numOfItems/2-1;i>=0;i--)
	{
		_vec=maxHeapify(_vec,i);
	}
	h->m_vec=_vec;
	return h;
}

static Vector* maxHeapify (Vector* _vec,int _i)
{
	int father,right,left, max;
	if(NULL==_vec)
	{
		return NULL;
	}
	VectorGet(_vec,_i,&father);
	VectorGet(_vec,2*_i+1,&left);
	VectorGet(_vec,2*_i+2,&right);		
	max= maxValue(father,left,right);
	if(max==left)
	{
		swap(_vec,2*_i+1,_i);
	}
	if(max==right)
	{
		swap(_vec,2*_i+2,_i);
	}
	return _vec;
}

static int maxValue(int _a,int _b,int _c)
{
	if(_a>=_b&&_a>=_c)
	{
		return _a;
	} 
	else if(_b>=_a&&_b>=_c)
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
	int index1value,index2value;
	VectorGet(_vec,i,&index1value);
	VectorGet(_vec,j,&index2value);
	VectorSet(_vec,i,index2value);
	VectorSet(_vec,j,index1value);
	return;
}

void HeapDestroy(Heap* _heap)
{
	_heap->m_heapSize=0;
	VectorDestroy(_heap->m_vec);
	free(_heap);
}

ADTErr HeapInsert(Heap* _heap,int _data)
{

	int numOfItem;
	if(NULL==_heap)
	{
		return ERR_NOT_INITIALIZED;
	}

	
	VectorAdd(_heap->m_vec,_data);
	VectorItemsNum(_heap->m_vec,&numOfItem);
	BubbleUp(_heap->m_vec,numOfItem);	
	
return ERR_OK;
}

static void BubbleUp (Vector* _vec,int _i)
{
	int father,son;
		
	while (_i/2>0)
	{
		printf("i/2-1 = %d\n",_i/2-1);
		printf("i-1 = %d\n",_i-1);
		VectorGet(_vec,_i/2-1,&father);
		VectorGet(_vec,_i-1,&son);
		printf("son = %d\n",son);
		printf("father = %d\n",father);

		if(son>father)
		{
			printf("swapping\n\n");
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

ADTErr HeapMax(Heap* _heap,int* _data)
{
	if(NULL==_heap)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorGet(_heap->m_vec, 0, _data);
	return ERR_OK;
}

ADTErr HeapExtractMax(Heap* _heap,int* _data)
{
	int i;
	int last;
	int temp;
	if(NULL==_heap)
	{
		return ERR_NOT_INITIALIZED;
	}	
	VectorGet(_heap->m_vec, _heap->m_heapSize-1, &last);
	VectorGet(_heap->m_vec,0, _data);
	printf("last = %d\n",last);
	swap(_heap->m_vec,0,HeapItemsNum(_heap)-1);
	_heap->m_heapSize--;
	temp=*_data;
	VectorDelete(_heap->m_vec,_data);
	VectorGet(_heap->m_vec,0, _data);
	*_data=temp;
	
	for(i=(_heap->m_heapSize)/2-2;i>=0;i--)
	{
		_heap->m_vec=maxHeapify(_heap->m_vec,i);
	}
	return ERR_OK;
}

int HeapItemsNum(Heap* _heap)
{
	int size;
	VectorItemsNum(_heap->m_vec,&size);
	return size;
}

void HeapPrint(Heap* _heap)
{
	if(NULL==_heap)
	{
		return;
	}
	VectorPrint(_heap->m_vec);
}

void Heapsort(Heap* _heap)
{
	int i,j;
	for(i=_heap->m_heapSize-1;i>=0;i--)
	{	printf("i = %d\n",i);
		swap(_heap->m_vec,0,i);
		for(j=_heap->m_heapSize/2-1;j>=0;j--)
		{
			_heap->m_vec=maxHeapify(_heap->m_vec,j);
		}
	}
}

static int IsDataFound (Heap* _heap,int _data)
{
	int numOfItem,i,value;
	VectorItemsNum(_heap->m_vec,&numOfItem);
	
	for(i=1;i<numOfItem+1;i++)
	{
		VectorGet(_heap->m_vec,i,&value);
		if(value==_data)
		{
			return 1;
		}
	}
return 0;
}

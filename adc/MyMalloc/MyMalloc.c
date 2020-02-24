/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: MyMalloc code
* 						DATE: 06-08-2019 17:12:07
*******************************************************************************/

#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include "MyMalloc.h"


void MyMallocInit(void* _memory, size_t _memorySize)
{
	int i;
	if(_memorySize<12)
	{
		return;
	}
	((size_t*)_memory)[0]=_memorySize;
	((size_t*)_memory)[1]=_memorySize-8;
	for(i=2;i<_memorySize;i++)
	{
		((size_t*)_memory)[i]=0;
	}
	return;
}

void* MyMalloc(void* _memory, size_t _requiredBlockSize)
{
	int i,j;	
	for(i=1;i<((size_t*)_memory)[0];i++)
	{
		if(((size_t*)_memory)[i]>_requiredBlockSize||((size_t*)_memory)[1]==((size_t*)_memory)[0]-8)
		{
			((size_t*)_memory)[i]=-_requiredBlockSize;
		}
	}
	if(i!=((size_t*)_memory)[0])
	{
		((size_t*)_memory)[i]=((size_t*)_memory)[0]-i;
	}
	
	for(j=_requiredBlockSize-1 ;j>=0;j--)
	{
		((size_t*)_memory)[i]=1;
	}
	return (void*)&(((size_t*)_memory)[i]);
}

void MyFree(void* _myBlock)
{
	int i;
	for(i=0;i<((size_t*)_myBlock)[0];i++)
	{
		((size_t*)_myBlock)[i]=0;
	}
	return;
}

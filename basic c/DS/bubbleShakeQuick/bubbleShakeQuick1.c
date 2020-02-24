/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: bubbleShakeQuick code
* 						DATE: 11-07-2019 15:00:57
*******************************************************************************/

#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include "bubbleShakeQuick.h"
#include "vector.h"

static void swap(Vector* _vec,int i,int j);
static int partition(Vector* _vec,int low, int high);

ADTErr bubbleSort(Vector* _vec)
{
	int i,j,size,aj,ajp1;
	if(NULL==_vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec,&size);
	for(i=1;i<size;i++)
	{
		for(j=1;j<size-i+1;j++)
		{
			VectorGet(_vec,j,&aj);
			VectorGet(_vec,j+1,&ajp1);
			if(aj>ajp1)
			{
				swap(_vec,j,j+1);
			}
		}
	}
	return ERR_OK;
}

ADTErr shakeSort(Vector* _vec)
{
	int i,s,size,ai,aip1,aim1;
	if(NULL==_vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec,&size);
	for(s=1;s<=size/2+1;s++)
	{
		for(i=s-1;i<size-s+1;i++)
		{
			VectorGet(_vec,i,&ai);
			VectorGet(_vec,i+1,&aip1);
			if(ai>aip1)
			{
				swap(_vec,i,i+1);
			}
		}
		for(i=size-s-1;i>=s;i--)
		{
			VectorGet(_vec,i,&ai);
			VectorGet(_vec,i-1,&aim1);
			if(ai<aim1)
			{
				swap(_vec,i,i-1);
			}
		}
		
	}
	return ERR_OK;
}

ADTErr insertionSort(Vector* _vec)
{
	int i,j,pivot,size,aj,ajp1;
	if(NULL==_vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec,&size);
	for(i=1;i<size;i++)
	{
		VectorGet(_vec,i,&pivot);
		j=i-1;
		VectorGet(_vec,j,&aj);		
		while(j>=0 && aj>pivot)
		{
			VectorGet(_vec,j,&ajp1);
			VectorSet(_vec,j+1,aj);
			j--;
			VectorGet(_vec,j,&aj);
		}
		VectorSet(_vec,j+1,pivot);
	}
}

ADTErr shellSort(Vector* _vec)
{
	int gap,i,ai,agap,len;
	VectorItemsNum(_vec,&len);
	len=len/2;
	for(gap=len;gap>=1;gap=gap/2)
	{
		for(i=0;i<len;i++)
		{
			printf("gap = %d\n",gap);
			VectorGet(_vec,i,&ai);
			VectorGet(_vec,i+gap,&agap);
			printf("ai = %d\n",ai);
			printf("agap = %d\n",agap);
			if(ai>agap)
			{
				printf("swapping\n");
				swap(_vec,i,i+gap);
			}
		}
		printf("vector = \n");
		VectorPrint(_vec);
		printf("\n\n");
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

static int partition(Vector* _vec,int low, int high)
{
	int pivot,i,j,ai,aj,aip1,ah;
	VectorGet(_vec,high,&pivot);
	i=low-1;
	
	for(j=low;j<=high-1;j++)
	{	
		VectorGet(_vec,j,&aj);
		if(aj<=pivot)
		{
			i++;
			VectorGet(_vec,i,&ai);
			swap(_vec,ai,aj);
		}		
	}
	swap(_vec,i+1,high);
	return i+1;
}

ADTErr quickSort(Vector* _vec,int low, int high)
{
	int pi;
	if(NULL==_vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	if(low<high)
	{
		pi=partition(_vec,low,high);
		quickSort(_vec,low,pi-1);
		quickSort(_vec,pi+1,high);
	}	
}

void printArr(Vector* _vec)
{
	if(NULL==_vec)
	{
		return;
	}
	VectorPrint(_vec);
}

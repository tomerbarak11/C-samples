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
#include <math.h>

static void swap(Vector* _vec,int i,int j);
static int partition(Vector* _vec,int low, int high);
static ADTErr insertionWithGap(Vector* _vec,int _gap,int _start);
static void MergeConnect(Vector* _vec, size_t _start, size_t _end);
static void MergeSortHelper(Vector* _vec, size_t _start, size_t _end);
static void checkRadixSort(Vector* _vec,int _digits);

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
	for(s=1;s<=size/2;s++)
	{
		for(i=s-1;i<size-s;i++)
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
	int i,pivot,size,aj,ajp1;
	if(NULL==_vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	insertionWithGap(_vec,1,0);
}

static ADTErr insertionWithGap(Vector* _vec,int _gap,int _start)
{
	int i,j,size,pivot,ai,aj,ajp1;
	VectorItemsNum(_vec,&size);

	for(i=_start;i<size;i=i+_gap)
	{
		VectorGet(_vec,i,&pivot);
		j=i-_gap;
		if(j>0)
		{
			VectorGet(_vec,j,&aj);
		}
		while(j>_start && aj>pivot)
		{		
			VectorGet(_vec,j,&aj);
			VectorSet(_vec,j+_gap,aj);
			j=j-_gap;
			VectorGet(_vec,j,&aj);
		}
		VectorSet(_vec,j+_gap,pivot);
	}

}

ADTErr shellSort(Vector* _vec)
{
	int gap,i,len,start;
	VectorItemsNum(_vec,&len);
	len=len/2;
	for(gap=len;gap>=1;gap=gap/2)
	{
		for(start=0;start<gap;start++)
		{
			insertionWithGap(_vec,gap,start);
		}	
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
			swap(_vec,i,j);
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

ADTErr selectionSort(Vector* _vec)
{
	int i,j=0,size,aj,min,minIndex=0,aMinIndex;
	if(NULL==_vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec,&size);
	
	for(i=0;i<size;i++)
	{
		VectorGet(_vec,i,&min);
		minIndex=i;
		for(j=i+1;j<size;j++)
		{
			VectorGet(_vec,j,&aj);
			VectorGet(_vec,i,&aMinIndex);
			if(aj<min)
			{
				minIndex=j;
				min=aj;
			}
		}
		swap(_vec,minIndex,i);
	}
}

ADTErr countingSort(Vector* _vec,int range)
{
	int i,num,size,dec;
	int* indexes;
	int* places;
	if(NULL==_vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	indexes=(int*)calloc(range,sizeof(int));
	if(NULL==indexes)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec,&size);
	places=(int*)calloc(size,sizeof(int));
	if(NULL==places)
	{
		return ERR_NOT_INITIALIZED;
	}

	for(i=0;i<size;i++)
	{
		VectorGet(_vec,i,&num);
		indexes[num]++;
	}
	for(i=0;i<range-1;i++)
	{
		indexes[i+1]=indexes[i+1]+indexes[i];
	}
	for(i=0;i<size;i++)
	{
		VectorGet(_vec,i,&dec);
		places[indexes[dec]-1]=dec;
		indexes[dec]--;
	}	
	for(i=0;i<size;i++)
	{
		VectorSet(_vec,i,places[i]);
	}	
}

ADTErr radixSort(Vector* _vec,int _digits)
{	
	int  i,numOfItems;
	if(NULL==_vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	for(i=0;i<_digits;i++)
	{
		checkRadixSort(_vec,i);
	}
	return ERR_OK;	
}

static void checkRadixSort(Vector* _vec,int _digits)
{
	int i,j,num,numOfItems,value;
	int digitsArr[10]={0};
	int *arr;
	VectorItemsNum(_vec,&numOfItems);
	arr=(int*)calloc(numOfItems,sizeof(int));
	if(NULL==_vec)
	{
		return;
	}
	for(i=0;i<numOfItems;i++)
	{
		VectorGet(_vec,i,&num);
		digitsArr[(num%((int)pow(10,_digits+1))) / (int)pow(10,_digits)]++;
	}
	/*====================================================================*/
	printf("original\n");
	VectorPrint(_vec);
	printf("\n");
	for(i=0;i<10;i++)
	{	
		printf("i = %d arr[i]=%d\n",i,digitsArr[i]);
	}
	printf("\n");
	/*====================================================================*/
	for(j=1;j<10;j++)
	{
		digitsArr[j]=digitsArr[j-1]+digitsArr[j];
	}
	printf("\nafter\n");
	for(i=0;i<10;i++)
	{	
		printf("i = %d arr[i]=%d\n",i,digitsArr[i]);
	}
	printf("\n");
	/*====================================================================*/
	
	for(j=numOfItems-1;j>=0;j--)
	{
		VectorGet(_vec,j,&value);
		arr[digitsArr[(value%((int)pow(10,_digits+1))) / (int)pow(10,_digits)]]=value;
		digitsArr[(value%((int)pow(10,_digits+1))) / (int)pow(10,_digits)]--;
	}
	
	for(j=numOfItems-1;j>=0;j--)
	{
		printf("arr[j]=%d\n",arr[j]);
		digitsArr[(value%((int)pow(10,_digits+1))) / (int)pow(10,_digits)]--;
	}
	
	for(i=0;i<numOfItems;i++)
	{
		VectorSet(_vec,i,arr[i]);
	}
	free(arr);
	printf("\n");
}

static void MergeSortHelper(Vector* _vec, size_t _start, size_t _end)
{
	if(_start==_end)
	{
		return;
	}
	MergeSortHelper(_vec,_start,(_start+_end)/2);
	MergeSortHelper(_vec,(_start+_end)/2+1, _end);
	MergeConnect(_vec,_start,_end);
}

ADTErr mergeSort(Vector* _vec)
{	
	int  numOfItems;
	if(NULL==_vec)
	{
		return ERR_NOT_INITIALIZED;
	}
	VectorItemsNum(_vec,&numOfItems);
	MergeSortHelper(_vec, 0, numOfItems);
	return ERR_OK;	
}

static void MergeConnect(Vector* _vec, size_t _start, size_t _end)
{
	size_t numOfItems, j, middleIndex, startIndex;
	int temp, startVal, middleVal;
	int* tempArr;
	
	numOfItems=_end-_start+1;
	j=0; 
	middleIndex=(_start+_end)/2+1;
	startIndex=_start;

	tempArr=(int*)malloc(numOfItems*sizeof(int));
	while(startIndex<=(_start+_end)/2&&middleIndex<=_end)
	{
		VectorGet(_vec, startIndex ,&startVal);
		VectorGet(_vec, middleIndex ,&middleVal);		
		if(startVal<middleVal)
		{	
			VectorGet(_vec, startIndex ,&temp);
			tempArr[j]=temp;
			++startIndex;
		}
		else
		{
			VectorGet(_vec, middleIndex ,&temp);
			tempArr[j]=temp; 
			++middleIndex;
		}
		++j;
	}
	while(middleIndex<=_end)
	{
		VectorGet(_vec, middleIndex ,&temp);
		tempArr[j]=temp; 
		++middleIndex;
		++j;
	}
	while(startIndex<=(_start+_end)/2)
	{
		VectorGet(_vec, startIndex ,&temp);
		tempArr[j]=temp;
		++startIndex;
		++j;
	}

	for(j=0;j<numOfItems;++j)
	{
		temp=tempArr[j];
		VectorSet(_vec, _start+j,temp);
	}
	free(tempArr);

}

void printArr(Vector* _vec)
{
	if(NULL==_vec)
	{
		return;
	}
	VectorPrint(_vec);
}

int isSorted(Vector* _vec)
{
	int i,len,ai,aip1;

	VectorItemsNum(_vec,&len);
	if(NULL==_vec)
	{
		return -1;
	}
	if(len>1)
	{
		for(i=1;i<len-1;i++)
		{
			VectorGet(_vec,i,&ai);
			VectorGet(_vec,i+1,&aip1);
			if(ai>aip1&&i+1<len)			
			{
				printf("i=%d\n",i);
				printf("i+1=%d\n",i+1);
				printf("ai=%d\n",ai);
				printf("ai+1=%d\n",aip1);
				return 0;
			}	
		}
	}
	return 1;
}

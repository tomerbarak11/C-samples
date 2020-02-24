#include "bubbleSortWithFunctionPointer.h"
#include <stdio.h> 

static void swap(int *_a, int *_b) 
{ 
    int temp = *_a; 
    *_a = *_b; 
    *_b = temp; 
} 

void bubbleSort(int (*f)(int,int),int _arr[], int _n) 
{
	int i, j,res;
	if(!f)
	{
		printf("pointer not allocated\n");
		return;
	}
	for (i = 0; i < _n-1; i++)
	{ 
		for (j = 0; j < _n-i-1; j++)  
		{
			res=(*f)(_arr[j],_arr[j+1]);
			if (res) 
			{
				swap(&_arr[j], &_arr[j+1]); 
			}
		}
	}
} 
  


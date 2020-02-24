#include "bubbleSortWithFunctionPointer.h"
#include <stdio.h>

static void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

static int lastDigitSort(int a,int b)
{
	if(a%10>b%10)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

static int intcmp(int a,int b)
{
	if(a>b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main() 
{ 
	int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
	int n = sizeof(arr)/sizeof(arr[0]);
	int choice;
	funcPointer fp;
	printf("enter choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
				printf("regular bubble sort\n");
				fp=intcmp;
				bubbleSort(fp,arr,n);
				break;
		case 2:
				printf("last digit sort\n");
				fp=lastDigitSort;
				bubbleSort(fp,arr,n);
				break;
	}
	
	printf("Sorted array:\n"); 
	printArray(arr, n); 
	return 0; 
} 

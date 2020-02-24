#include "bubbleSortWithFunctionPointer.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10
static void printArray(void** arr, int size);
static int lastDigitSort(void* a,void* b);
static int intcmp(void* a,void* b);

static void printArray(void** arr, int size) 
{ 
    int i; 
    printf("size = %d\n",size);
    for (i=0; i < size; i++)
    {
       printf("%d ",*(int*) arr[i]);
	}
    printf("\n"); 
} 

static int lastDigitSort(void* a,void* b)
{
	if(*(int*)a%10>*(int*)b%10)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

static int intcmp(void* a,void* b)
{
	if(*(int*)a>*(int*)b)
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
	int *arr;
	void** voidPointers;
	int n = sizeof(arr)/sizeof(int);
	int choice;
	int i;
	funcPointer fp;
	srand(time(NULL));
	voidPointers=(void**)malloc(SIZE*sizeof(void*));
	for(i=0;i<SIZE;i++)
	{
		arr[i]=rand()%100;
	}
	for(i=0;i<SIZE;i++)
	{
		printf("arr[i]=%d\n",arr[i]);
	}
	for(i=0;i<SIZE;i++)
	{
		voidPointers[i]=&arr[i];
	}
	printf("enter choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
				printf("regular bubble sort\n");
				fp=intcmp;
				bubbleSort(fp,voidPointers,SIZE);
				break;
		case 2:
				printf("last digit sort\n");
				fp=lastDigitSort;
				bubbleSort(fp,voidPointers,SIZE);
				break;
	}
	
	printf("Sorted array:\n"); 
	printArray(voidPointers, SIZE); 
	return 0; 
} 

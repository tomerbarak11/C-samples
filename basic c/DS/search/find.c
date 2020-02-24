/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: doublelinked testing
* 						DATE: 02-07-2019 16:18:05
*******************************************************************************/

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#define SIZE1 1000000

int findNumRegular(int arr[],int num);
int findNumSmart(int arr[],int num);

int main()
{
	int arr[SIZE1],num=123;
	printf("index1 = %d\n",findNumRegular(arr,num));
	printf("\n");
	printf("index2 = %d\n",findNumSmart(arr,num));
}

int findNumRegular(int arr[],int num)
{	
	clock_t t=clock();
	double time1;
	int i;
	srand(time(NULL));
	
	for(i=0;i<SIZE1;i++)
	{
		arr[i]=rand()%SIZE1;
	}
	for(i=0;i<SIZE1;i++)
	{
		if(arr[i]==num)
		{
			time1=(double)(clock()-t)/CLOCKS_PER_SEC;
			printf("the time is: %f\n",time1);
			printf("found\n");
			return i;
		}
	}
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	printf("not found\n");
	return -1;
}

int findNumSmart(int arr[],int num)
{	
	clock_t t=clock();
	double time1;
	int i=0;
	srand(time(NULL));
	
	for(i=0;i<SIZE1;i++)
	{
		arr[i]=rand()%SIZE1;
	}
	i=0;
	if(arr[SIZE1-1]==num)
	{
		return SIZE1-1;
	}
	arr[SIZE1-1]=num;
	while(1)
	{
		if(arr[i]==num)
		{
			time1=(double)(clock()-t)/CLOCKS_PER_SEC;
			printf("the time is: %f\n",time1);
			if(i==SIZE1-1)
			{
				printf("not found\n");
				return -1;
			}
			else
			{
				printf("found\n");
				return i;
			}
		}
		i++;
	}
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	return -1;
}


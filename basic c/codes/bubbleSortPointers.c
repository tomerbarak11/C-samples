#include <stdio.h>
#define LEN 5
void bubbleSort(int _arr[], int _n,int *_par[]);
void printArray(int *_arr[], int _size);
void swap(int *_a, int *_b);

int main()
{
	int arr[] = {18, 3, 12, 11, 42};
	int *parr[5],i;
	for(i=0;i<LEN;i++)
	{
		parr[i]=&arr[i];
	}
	printf("before\n");
	for(i=0;i<LEN;i++)
	{
		printf("%d\n",*parr[i]);
	}
	bubbleSort(arr,LEN,parr);
	printArray(parr,LEN);
}

void swap(int *_a, int *_b)
{
	int temp = *_a;
	*_a = *_b;
	*_b = temp;
}

void bubbleSort(int _arr[], int _n,int *_parr[])
{
	int i, j;
	for (i = 0; i < _n-1; i++)
	{
		for (j = 0; j < _n-i-1; j++)
			if (_arr[j] > _arr[j+1])
			{
				swap(_parr[j], _parr[j+1]);
			}
		break;
	}
}

void printArray(int *_parr[], int _size)
{
	int i;
	printf("by pointers:\n");
	for (i=0; i < _size; i++)
	{
		printf("%d\n", *_parr[i]);
	}
}

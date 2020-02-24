#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000

#define SWAP(x,y) \
{				  \
	int temp=x;       \
	x=y;              \
	y=temp;          \
}

void swap(int _x,int _y);

int main()
{
	int array[SIZE];
	int i=0, j=0;
	clock_t t; 
	double time;
	
	for(i=0;i<SIZE;i++)
	{
		array[i]=rand()%100;
	}
	t=clock();

	for(i=0;i<SIZE;i++) 
	{
		for(j=0;j<SIZE;j++)
		{
			if(array[i]>array[i+1])
			{
				SWAP(array[i],array[i+1]);
			}
		}
	}
	time=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f",time);
	
	return 0;
}


void swap(int _x,int _y)
{  
	int temp=_x;       
	_x=_y;              
	_y=temp;   
}

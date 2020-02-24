#include <stdio.h>
float avg(int arr[],int n,int i);
int main()
{
	int arr[]={1,2,3,4};
	int i=0;
	printf("avg=%.2f\n",avg(arr,sizeof(arr)/sizeof(int),i));
}

float avg(int arr[],int n,int i)
{
	if(i==n)
	{
		return 0;
	}
	else
	{
		return (((float)arr[i]/n))+avg(arr,n,++i);
	}
	
}


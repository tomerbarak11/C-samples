#include <stdio.h>
int maxRec(int arr[],int i,int n,int max);
int main()
{
	int arr[]={5,7,2,4,1};
	int i=0;
	int max=arr[0];
	printf("max = %d\n",maxRec(arr,i,sizeof(arr)/sizeof(int),max));
}

int maxRec(int arr[],int i,int n,int max)
{
	if(i+1==n)
	{
		return max;
	}
	else if(arr[i+1]>=max)
	{
		max=arr[i+1];
	}
	return maxRec(arr,++i,n,max);
}

#include <stdio.h>
int sumRec(int arr[],int i,int n);
int main()
{
	int arr[]={1,2,3,4,5};
	int i=0;
	printf("sum=%d\n",sumRec(arr,i,5));
}

int sumRec(int arr[],int i,int n)
{
	if(i==5)
	{
		return 0;
	}
	return arr[i]+sumRec(arr,i+1,5);
}

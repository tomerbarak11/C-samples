#include <stdio.h>
void flipChars(char arr[],int n,int l,int r);
void print(char arr[],int n);

int main()
{
	char arr[]={'a','b','c','d','e','f','g'};
	print(arr,sizeof(arr)/sizeof(char));
	flipChars(arr,sizeof(arr)/sizeof(char),0,sizeof(arr)/sizeof(char)-1);
	print(arr,sizeof(arr)/sizeof(char));
}

void flipChars(char arr[],int n,int l,int r)
{
	char temp;
	if(l>=(n/2)||r<=(n/2))
	{
		return;
	}
	
	temp=arr[l];
	arr[l]=arr[r];
	arr[r]=temp;
	
	return flipChars(arr,n,++l,--r);
}

void print(char arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%c\n",arr[i]);
	}
	printf("\n");
}

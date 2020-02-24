#include <stdio.h>
void decToBinary(int n);
int rotateRight(unsigned char c,int n);

int main()
{
	int n=3;
	unsigned char c='a';	
	rotateRight(c,n);
}

int rotateRight(unsigned char c,int n)
{
	int res;
	res=(c>>n)|(c<<8-n);
	decToBinary(res);
}

void decToBinary(int n) 
{ 
	int i; 

	for (i=0;i<8;i++) 
	{
		printf("%d",(n>>(8-i-1))&1);
	}
	printf("\n"); 
} 

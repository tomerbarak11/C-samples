#include <stdio.h>
void mulTable(int n,int l,int r);
void row(int n,int l,int r);

int main()
{
	int l=1,r=1,n=10;
	mulTable(n,l,r);
}

void mulTable(int n,int l,int r)
{
	if (l==n+1)
	{
		return;
	}
	row(n,l,r);
	printf("\n");
	mulTable(n,++l,r);
}

void row(int n,int l,int r)
{
	if(r==n+1)
	{
		return;
	}
	printf("%4d",l*r);
	row(n,l,++r);
}



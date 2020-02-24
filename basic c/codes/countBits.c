#include <stdio.h>
#define ROW 256
#define COL 256
void setLookUpTableBitsOnMat(int matBits[ROW][COL]);
void setLookUpTableBitsOn(int *lookUpTableBitsOn);
int countBitsOn(unsigned int n);
void flipBit(unsigned n,int i);
void flipBitWithTable(unsigned n,int i,int matBits[ROW][COL]);
void flip2Bits(unsigned n,int i1,int i2);

int main()
{
	unsigned int i=2,j,k,index,n=11;
	int lookUpTableBitsOn[ROW];
	int matBits[ROW][COL]={0};
	
	setLookUpTableBitsOn(lookUpTableBitsOn);
	setLookUpTableBitsOnMat(matBits);

	flipBit(n,i);
	
	flipBitWithTable(11,2,matBits);
	flip2Bits(n,1,2);
}

void setLookUpTableBitsOn(int *lookUpTableBitsOn)
{ 	
	int j;
	for(j=0;j<ROW;j++) 
 	{ 	
		lookUpTableBitsOn[j]=countBitsOn(j); 
	}
}			 

void setLookUpTableBitsOnMat(int matBits[ROW][COL])
{
	int i,j,k,index;
	for(i=0;i<ROW;i++,k++)
	{	
		k=i;
		index=i;
		for(j=0;j<COL;j++)
		{
			matBits[i][j]=index%2;
			index=k/2;
			k=k/2;
		}	
	}
	for(i=0;i<ROW;i++)
	{		
		printf("i = %d\n",i);
		for(j=7;j>=0;j--)
		{
			printf("%d",matBits[i][j]);
		}	
		printf("\n");
	}
}

int countBitsOn(unsigned int n)
{
	int i,countBits=0,temp=n,on=0;
	int e;
	while(temp)
	{
		temp=temp/2;
		countBits++;
	}
	for(i=0;i<countBits;i++)
	{
		e=n&(1<<i);
		if(e)
		{
			on++;
		}
	}
	return on;
}

void flipBit(unsigned n,int i)
{	
	n^=(1<<i);
}

void flipBitWithTable(unsigned n,int i,int matBits[ROW][COL])
{	
	int k;
	n^=(1<<i);
	for(k=0;k<COL;k++)
	{
		matBits[n][k]=n%2;
		n=n/2;
	}		
}

void flip2Bits(unsigned n,int i1,int i2)
{	
	n^=(1<<i1);
	n^=(1<<i2);
}

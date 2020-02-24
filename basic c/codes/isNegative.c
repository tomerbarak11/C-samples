#include <stdio.h>

void decToBinary(int n);
int rotateRight(int num);

int main()
{
	int num=-6;
	printf("is %d\n",!!rotateRight(num));
}

int rotateRight(int num)
{
	int one=1;
	int res;
	one=((one>>1)|(one<<sizeof(int)*8-1));
	return one&num;
}

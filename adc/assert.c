#define NDEBUG
#include <stdio.h>
#include <assert.h>
int main()
{
	int i=10;
	int j=20;
	assert(i==10);
	assert(j==i);
}

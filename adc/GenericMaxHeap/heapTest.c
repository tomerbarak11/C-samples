#include "mu_test.h"/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: doublelinked testing
* 						DATE: 02-07-2019 16:18:05
*******************************************************************************/

#include <assert.h>
#include "heap.h"
#include <time.h>
#define SIZE 10

/*
 @author: Muhammad Zahalqa
 @contact: m@tryfinally.com

 ©2019
 μ_test 0.42 demo.

 the directory conatins:
 mu_test.h 		: mu test framework
 funcs.c/h 		: functions to be tested in demo
 test.c 		: test

 Compile with
	gcc -ansi -pedantic -Wall -Wextra funcs.c test.c -o test

 Run:
 	./test
 	./test -v
 */
static int compareInt(const void* _a,const void* _b);
static void printIntHeap(const void* _item, void* context);
static int printHeap(const void* _item, void* context);
static void printIntHeap(const void* _item, void* context)
{
	printf("item = %d\n",*(int*)_item);
}

static int printHeap(const void* _item, void* context)
{
	if(_item!=NULL)
	{
		printf("item = %d\n",*(int*)_item);
	}
	else
	{
		return 0;
	}
}

static int compareInt(const void* _a,const void* _b)
{
	if(NULL==_a||NULL==_b)
	{
		return 0;
	}
		
	if(*(int*)_a>=*(int*)_b)
	{
		return 1;
	}
	return 0;
}

UNIT(max_Heapify)
	Vector* v=NULL;
	Heap* h=NULL;
	LessThanComparator fp=compareInt;
	ActionFunction voidPrinter = printHeap;

	int i,*num;

	v=VectorCreate(50,100);
	srand(time(NULL));
	for(i=0;i<SIZE+1;i++)
	{
		num=(int*)malloc(1*sizeof(int));
		*num=rand()%SIZE;		
		/*voidPointer=&num;*/
		VectorAppend(v,num);
	}
	
	h=HeapBuild(v,fp);
	ASSERT_THAT(NULL!=h);
	HeapPeek(h);
	printf("\n");
	ASSERT_THAT(HeapForEach(h,voidPrinter,NULL) !=0);
	HeapDestroy(&h);
	HeapForEach(h,voidPrinter,NULL);
	ASSERT_THAT(HeapForEach(h,voidPrinter,NULL) ==0);
END_UNIT

TEST_SUITE(Dynamic Vector Module Unit Test)
	TEST(max_Heapify)

	/*TEST(Heap_Sort)*/
END_SUITE

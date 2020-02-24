#include "mu_test.h"/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: doublelinked testing
* 						DATE: 02-07-2019 16:18:05
*******************************************************************************/

#include <assert.h>
#include "heap.h"


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

UNIT(max_Heapify)
	Vector* v=NULL;
	Heap* h=NULL;
	int max;
	v=VectorCreate(50,100);
	VectorAdd(v,4);
	VectorAdd(v,1);
	VectorAdd(v,3);
	VectorAdd(v,2);
	VectorAdd(v,16);
	VectorAdd(v,9);
	VectorAdd(v,10);
	VectorAdd(v,14);
	VectorAdd(v,8);
	VectorAdd(v,7);
	h=HeapBuild(v);
	ASSERT_THAT(NULL!=h);
	HeapPrint(h);
	HeapExtractMax(h,&max);
	printf("\n");
	printf("after extract\n");
	HeapPrint(h);
	printf("\n");
	HeapPrint(h);
END_UNIT

UNIT(Heap_Insert)
	Vector* v=NULL;
	Heap* h=NULL;
	int max;
	v=VectorCreate(50,100);
	VectorAdd(v,4);
	VectorAdd(v,1);
	VectorAdd(v,3);
	VectorAdd(v,2);
	VectorAdd(v,16);
	VectorAdd(v,9);
	VectorAdd(v,10);
	VectorAdd(v,14);
	VectorAdd(v,8);
	VectorAdd(v,11);
	h=HeapBuild(v);
	HeapInsert(h,17);
	printf("after insert\n");
	HeapPrint(h);
END_UNIT

UNIT(Heap_Max)
	Vector* v=NULL;
	Heap* h=NULL;
	int max;
	v=VectorCreate(50,100);
	VectorAdd(v,4);
	VectorAdd(v,1);
	VectorAdd(v,3);
	VectorAdd(v,2);
	VectorAdd(v,16);
	VectorAdd(v,9);
	VectorAdd(v,10);
	VectorAdd(v,14);
	VectorAdd(v,8);
	VectorAdd(v,7);
	h=HeapBuild(v);
	HeapMax(h,&max);
	ASSERT_THAT(max==16);
END_UNIT

UNIT(Heap_ExtractMax)
	Vector* v=NULL;
	Heap* h=NULL;
	int max,newMax;
	v=VectorCreate(50,100);
	VectorAdd(v,4);
	VectorAdd(v,1);
	VectorAdd(v,3);
	VectorAdd(v,2);
	VectorAdd(v,16);
	VectorAdd(v,9);
	VectorAdd(v,10);
	VectorAdd(v,14);
	VectorAdd(v,8);
	VectorAdd(v,7);
	h=HeapBuild(v);
	HeapExtractMax(h,&max);
	ASSERT_THAT(max==16);
	HeapMax(h,&newMax);
	ASSERT_THAT(newMax==14);
END_UNIT

UNIT(Heap_ItemsNum)
	Vector* v=NULL;
	Heap* h=NULL;
	int max;
	v=VectorCreate(50,100);
	VectorAdd(v,4);
	VectorAdd(v,1);
	VectorAdd(v,3);
	VectorAdd(v,2);
	VectorAdd(v,16);
	VectorAdd(v,9);
	VectorAdd(v,10);
	VectorAdd(v,14);
	VectorAdd(v,8);
	VectorAdd(v,7);
	h=HeapBuild(v);
	ASSERT_THAT(10==HeapItemsNum(h));
	HeapExtractMax(h,&max);
	ASSERT_THAT(9==HeapItemsNum(h));
END_UNIT

UNIT(Heap_Sort)
	Vector* v=NULL;
	Heap* h=NULL;
	int max;
	v=VectorCreate(50,100);
	VectorAdd(v,4);
	VectorAdd(v,1);
	VectorAdd(v,3);
	VectorAdd(v,2);
	VectorAdd(v,16);
	VectorAdd(v,9);
	VectorAdd(v,10);
	VectorAdd(v,14);
	VectorAdd(v,8);
	VectorAdd(v,7);
	h=HeapBuild(v);
	HeapPrint(h);
	Heapsort(h);
	printf("\n");
	HeapPrint(h);
END_UNIT

TEST_SUITE(Dynamic Vector Module Unit Test)
	TEST(max_Heapify)
	TEST(Heap_Insert)
	TEST(Heap_Max)
	TEST(Heap_ExtractMax)
	TEST(Heap_ItemsNum)
	TEST(Heap_Sort)
END_SUITE

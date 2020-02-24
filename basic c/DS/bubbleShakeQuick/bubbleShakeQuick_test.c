#include "mu_test.h"/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: doublelinked testing
* 						DATE: 02-07-2019 16:18:05
*******************************************************************************/

#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include "vector.h"
#include "bubbleShakeQuick.h"
#include <stdio.h>
#define SIZE1 10000
#define SIZE2 20000
#define SIZE3 50000
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

UNIT(bubble_Sort)
	clock_t t=clock();
	Vector* v;
	double time1;
	int i,flag;
	v=VectorCreate(SIZE1+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE1;i++)
	{
		VectorAdd(v,rand()%SIZE1);
	}
	bubbleSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
/*==========================================================*/	
	v=VectorCreate(SIZE2+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE2;i++)
	{
		VectorAdd(v,rand()%SIZE2);
	}
	bubbleSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
/*==========================================================*/	
	v=VectorCreate(SIZE3+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE3;i++)
	{
		VectorAdd(v,rand()%SIZE3);
	}
	bubbleSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
END_UNIT

UNIT(shake_Sort)
	clock_t t=clock();
	Vector* v;
	double time1;
	int i,flag;
	
	v=VectorCreate(SIZE1+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE1;i++)
	{
		VectorAdd(v,rand()%SIZE1);
	}
	shakeSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
/*==========================================================*/	
	v=VectorCreate(SIZE2+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE2;i++)
	{
		VectorAdd(v,rand()%SIZE2);
	}
	shakeSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
/*==========================================================*/	
	v=VectorCreate(SIZE3+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE3;i++)
	{
		VectorAdd(v,rand()%SIZE3);
	}
	shakeSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	VectorDestroy(v);
END_UNIT

UNIT(insertion_Sort)
	clock_t t=clock();
	Vector* v;
	double time1;
	int i,flag;
	
	v=VectorCreate(SIZE1+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE1;i++)
	{
		VectorAdd(v,rand()%SIZE1);
	}
	insertionSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
/*==========================================================*/	
	v=VectorCreate(SIZE2+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE2;i++)
	{
		VectorAdd(v,rand()%SIZE2);
	}
	insertionSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
/*==========================================================*/	
	v=VectorCreate(SIZE3+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE3;i++)
	{
		VectorAdd(v,rand()%SIZE3);
	}
	insertionSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	VectorDestroy(v);
END_UNIT

UNIT(shell_Sort)
	clock_t t=clock();
	Vector* v;
	double time1;
	int i,flag;
	v=VectorCreate(1000+1,1);
	srand(time(NULL));
	for(i=0;i<1000;i++)
	{
		VectorAdd(v,rand()%1000);
	}
	shellSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
	/*==========================================================*/	
	v=VectorCreate(SIZE2+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE2;i++)
	{
		VectorAdd(v,rand()%SIZE2);
	}
	shellSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
/*==========================================================*/	
	v=VectorCreate(SIZE3+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE3;i++)
	{
		VectorAdd(v,rand()%SIZE3);
	}
	shellSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	VectorDestroy(v);
	
END_UNIT

UNIT(quick_Sort)
	clock_t t=clock();
	Vector* v;
	double time1;
	int i,flag;
	v=VectorCreate(SIZE1+1,1000);
	srand(time(NULL));
	for(i=0;i<SIZE1;i++)
	{
		VectorAdd(v,rand()%SIZE1);
	}
	quickSort(v,0,SIZE1-1);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
/*==========================================================*/	
	v=VectorCreate(SIZE2+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE2;i++)
	{
		VectorAdd(v,rand()%SIZE2);
	}
	quickSort(v,0,SIZE2-1);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
/*==========================================================*/	
	v=VectorCreate(SIZE3+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE3;i++)
	{
		VectorAdd(v,rand()%SIZE3);
	}
	quickSort(v,0,SIZE3-1);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
END_UNIT

UNIT(selection_sort)
	clock_t t=clock();
	Vector* v;
	double time1;
	int i,flag;
	v=VectorCreate(SIZE1+1,1000);
	srand(time(NULL));
	for(i=0;i<SIZE1;i++)
	{
		VectorAdd(v,rand()%10);
	}
	selectionSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
/*==========================================================*/	
	v=VectorCreate(SIZE2+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE2;i++)
	{
		VectorAdd(v,rand()%SIZE2);
	}
	selectionSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
/*==========================================================*/	
	v=VectorCreate(SIZE3+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE3;i++)
	{
		VectorAdd(v,rand()%SIZE3);
	}
	selectionSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
END_UNIT

UNIT(counting_Sort)
	clock_t t=clock();
	Vector* v;
	double time1;
	int i,flag;
	v=VectorCreate(SIZE1+1,1000);
	srand(time(NULL));
	for(i=0;i<SIZE1;i++)
	{
		VectorAdd(v,rand()%SIZE1);
	}
	countingSort(v,SIZE1);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
/*==========================================================*/	
	v=VectorCreate(SIZE2+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE2;i++)
	{
		VectorAdd(v,rand()%SIZE2);
	}
	countingSort(v,SIZE2);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
/*==========================================================*/	
	v=VectorCreate(SIZE3+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE3;i++)
	{
		VectorAdd(v,rand()%SIZE3);
	}
	countingSort(v,SIZE3);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
END_UNIT

UNIT(merge_Sort)
	clock_t t=clock();
	Vector* v;
	double time1;
	int i,flag;
	v=VectorCreate(SIZE1+1,1000);
	srand(time(NULL));
	for(i=0;i<SIZE1;i++)
	{
		VectorAdd(v,rand()%1000);
	}
	mergeSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
/*==========================================================*/	
	v=VectorCreate(SIZE2+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE2;i++)
	{
		VectorAdd(v,rand()%SIZE2);
	}
	mergeSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
/*==========================================================*/	
	v=VectorCreate(SIZE3+1,1);
	srand(time(NULL));
	for(i=0;i<SIZE3;i++)
	{
		VectorAdd(v,rand()%SIZE3);
	}
	mergeSort(v);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
END_UNIT

UNIT(radix_Sort)
	clock_t t=clock();
	Vector* v;
	double time1;
	int i,flag;
/*==========================================================*/
	v=VectorCreate(20+1,1);
	srand(time(NULL));
	for(i=0;i<20;i++)
	{
		VectorAdd(v,rand()%100);
	}
	radixSort(v,2);
	time1=(double)(clock()-t)/CLOCKS_PER_SEC;
	printf("the time is: %f\n",time1);
	flag=isSorted(v);
	ASSERT_THAT(1==flag);
	VectorDestroy(v);
	

END_UNIT

TEST_SUITE(Dynamic Vector Module Unit Test)
	/*TEST(bubble_Sort)
	TEST(shake_Sort)
	TEST(insertion_Sort)
	TEST(shell_Sort)
	TEST(quick_Sort)
	TEST(selection_sort)
	TEST(counting_Sort)
	TEST(merge_Sort)*/
	TEST(radix_Sort)
END_SUITE

/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: MyMalloc testing
* 						DATE: 06-08-2019 17:12:07
*******************************************************************************/
#include "mu_test.h"
#include <assert.h>
#include "MyMalloc.h"
#include <stdlib.h> 

UNIT(MyMallocInitTest)
	size_t* arr=NULL;
	arr=(size_t*)calloc(1000,sizeof(size_t));
	if(NULL==arr)
	{
		exit(1);
	}
	MyMallocInit(arr,1000);
END_UNIT

UNIT(MyMallocTest)
	size_t* arr=NULL;
	arr=(size_t*)calloc(1000,sizeof(size_t));
	if(NULL==arr)
	{
		exit(1);
	}
	MyMallocInit(arr,1000);
	MyMalloc(arr,200);
END_UNIT

UNIT(MyFreeTest)
	size_t* arr=NULL;
	arr=(size_t*)calloc(1000,sizeof(size_t));
	if(NULL==arr)
	{
		exit(1);
	}
	MyMallocInit(arr,1000);
	MyFree(arr);
END_UNIT

TEST_SUITE(Dynamic Vector Module Unit Test)
	TEST(MyMallocInitTest)
	TEST(MyMallocTest)	
	TEST(MyFreeTest)		
END_SUITE


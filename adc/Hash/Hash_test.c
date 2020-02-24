#include "mu_test.h"/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: Hash testing
* 						DATE: 28-07-2019 13:41:25
*******************************************************************************/

#include <assert.h>
#include <stdio.h>
#include <time.h>
#include "Hash.h"
#define SIZE1 7
#define SIZE2 7
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


/**************************************Static Functions*******************************************/
static int PrintKeyAndValue(const void* _key, void* _value, void* _context);

int equalInt(const void* _firstKey, const void* _secondKey);
size_t formulaInt(const void* _key);
static void destroyKey(void* _key);
static void destroyValue(void* _value);

/**************************************Static Functions*******************************************/
static int PrintKeyAndValue(const void* _key, void* _value, void* _context)
{
	if(NULL==_key)
	{
		printf("11111111111111111111\n");
		return 0;
	}
	else
	{
		printf("Key= %d, Value= %d\n",*(int*)_key,*(int*)_value);
		return 1;
	}
}

int equalInt(const void* _firstKey, const void* _secondKey)
{
	if(*(int*)_firstKey>*(int*)_secondKey)
	{
		return 1;
	}
	else if(*(int*)_firstKey<*(int*)_secondKey)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

size_t formulaInt(const void* _key)
{
	return *(int*)_key;
}

static void destroyKey(void* _key)
{
	free(_key);
}

static void destroyValue(void* _value)
{
	free(_value);
}
/**************************************Static Functions*******************************************/

UNIT(HashMap_Create_TEST)
	HashMap* hm=NULL;
	HashFunction hf=formulaInt;
	EqualityFunction ef=equalInt;
	hm=HashMap_Create(SIZE1,hf,ef);
	ASSERT_THAT(hm!=NULL);
END_UNIT

UNIT(HashMap_Destroy_TEST)
	int i;
	int *key;
	int *value;
	
	HashMap* hm=NULL;
	HashFunction hf=formulaInt;
	EqualityFunction ef=equalInt;
	_elementDestroy destroyKey;
	_elementDestroy destroyValue;
	hm=HashMap_Create(SIZE1,hf,ef);
	for(i=0;i<SIZE2;i++)
	{
		key=(int*)malloc(1*sizeof(int));
		value=(int*)malloc(1*sizeof(int));
		*key=rand()%10;
		*value=rand()%100;
		printf("key = %d\n",*key);
		printf("value = %d\n",*value);
		HashMap_Insert(hm,(const void*)key,(const void*)value);
	}
	HashMap_Destroy(&hm,destroyKey,destroyValue);
	ASSERT_THAT(hm==NULL);
END_UNIT

UNIT(HashMap_Rehash_TEST)
	int i;
	int *key;
	int *value;
	
	HashMap* hm=NULL;
	HashFunction hf=formulaInt;
	EqualityFunction ef=equalInt;
	hm=HashMap_Create(SIZE1,hf,ef);
	for(i=0;i<SIZE2;i++)
	{
		key=(int*)malloc(1*sizeof(int));
		value=(int*)malloc(1*sizeof(int));
		*key=rand()%10;
		*value=rand()%100;
		printf("key = %d\n",*key);
		printf("value = %d\n",*value);
		HashMap_Insert(hm,key,value);
	}		
	printf("\n\n");
	HashMap_Rehash(hm,13);
END_UNIT

UNIT(HashMap_Remove_TEST)
	int i;
	int *key;
	int *value;
	int searchKey;
	void *saveKey;
	void *saveVal;
	HashMap* hm=NULL;
	KeyValueActionFunction kvaf=PrintKeyAndValue;
	HashFunction hf=formulaInt;
	EqualityFunction ef=equalInt;
	hm=HashMap_Create(SIZE1,hf,ef);
	searchKey=3;
	for(i=0;i<SIZE2;i++)
	{
		key=(int*)malloc(1*sizeof(int));
		if(NULL==key)
		{
			exit(1);
		}
		value=(int*)malloc(1*sizeof(int));
		*key=rand()%10;
		*value=rand()%100;
		printf("key = %d\n",*key);
		printf("value = %d\n",*value);
		HashMap_Insert(hm,key,value);
	}		
	printf("\n\n");
	printf("Before removing\n");
	printf("Number of items = %ld\n",HashMap_ForEach(hm,kvaf,NULL));
	HashMap_Remove(hm,(const int*)&searchKey,&saveKey,&saveVal);
	printf("After removing\n");
	printf("Number of items = %ld\n",HashMap_ForEach(hm,kvaf,NULL));
END_UNIT

UNIT(HashMap_Size_TEST)
	int i;
	int *key;
	int *value;
	
	HashMap* hm=NULL;
	HashFunction hf=formulaInt;
	EqualityFunction ef=equalInt;
	hm=HashMap_Create(SIZE1,hf,ef);
	for(i=0;i<SIZE2;i++)
	{
		key=(int*)malloc(1*sizeof(int));
		value=(int*)malloc(1*sizeof(int));
		*key=rand()%10;
		*value=rand()%100;
		printf("key = %d\n",*key);
		printf("value = %d\n",*value);
		HashMap_Insert(hm,key,value);
	}		
	printf("\n\n");
	printf("Number of items = %ld\n",HashMap_Size(hm));
END_UNIT

UNIT(For_Each_TEST)
	int i;
	int *key;
	int *value;
	
	HashMap* hm=NULL;
	KeyValueActionFunction kvaf=PrintKeyAndValue;
	HashFunction hf=formulaInt;
	EqualityFunction ef=equalInt;
	hm=HashMap_Create(SIZE1,hf,ef);
	for(i=0;i<SIZE2;i++)
	{
		key=(int*)malloc(1*sizeof(int));
		value=(int*)malloc(1*sizeof(int));
		*key=rand()%10;
		*value=rand()%100;
		printf("key = %d\n",*key);
		printf("value = %d\n",*value);
		HashMap_Insert(hm,key,value);
	}		
	printf("\n\n");
	printf("Number of items = %ld\n",HashMap_ForEach(hm,kvaf,NULL));
END_UNIT

TEST_SUITE(Dynamic Vector Module Unit Test)
	/*TEST(HashMap_Create_TEST)*/
	TEST(HashMap_Destroy_TEST)
	/*TEST(HashMap_Rehash_TEST)*/
	/*TEST(HashMap_Remove_TEST)*/
	/*TEST(HashMap_Size_TEST)*/
	/*TEST(For_Each_TEST)*/
END_SUITE

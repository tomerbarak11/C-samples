/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: Hash code
* 						DATE: 28-07-2019 13:41:25
*******************************************************************************/

#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy     
                     */
#include "Hash.h"
#include "list.h"
#include "list_itr.h"
#include <math.h>
#define MAGIC_NUMBER 0xBEEFBEEF
#define DEAD_MAGIC_NUMBER 0xBEEFBEEF
typedef struct Pair Pair;
struct HashMap
{
	size_t m_magicNumber;
	List **m_buckets;
	size_t m_capacity;
	HashFunction m_hashFunc;
	EqualityFunction m_equalFunc;
};

struct Pair
{
	void* m_key;
	void* m_value;
};
/********************************Static Functions**************************************/
static Pair* PairCreate(const void *_key,const void* _value);
static int isUnique(HashMap* _map,size_t indexToInsert,const void* _key);
static int getPrime(int _capacity);
static int doHashMap_ForEach(ListItr _l,KeyValueActionFunction _action, void* _context);
/********************************Static Functions**************************************/
HashMap* HashMap_Create(size_t _capacity, HashFunction _hashFunc, EqualityFunction _keysEqualFunc)
{
	HashMap *hm=NULL;
	int i;
	if(NULL==_hashFunc||NULL==_keysEqualFunc)
	{
		return NULL;
	}
	
	hm=(HashMap*)malloc(1*sizeof(HashMap));
	if(NULL==hm)
	{
		return NULL;
	}
	
	hm->m_capacity=getPrime(_capacity);
	hm->m_magicNumber=MAGIC_NUMBER;
	hm->m_buckets=(List**)calloc(hm->m_capacity,sizeof(List*));
	if(NULL==hm->m_buckets)
	{
		free(hm);
		return NULL;
	}
	
	for(i=0;i<_capacity;i++)
	{
		hm->m_buckets[i]=ListCreate();
		if(NULL==hm->m_buckets[i])
		{
			return NULL;
		}
	}
	
	hm->m_hashFunc=_hashFunc;
	hm->m_equalFunc=_keysEqualFunc;
	return hm;
}

static int getPrime(int _capacity)
{
	int i;
	int flag=0;
	if(_capacity==0)
	{
		return 0;
	}
		if(_capacity==1)
	{
		return 1;
	}
	while(1)
	{
		for(i=sqrt(_capacity);i>=2;i--)
		{
			flag=0;
			if(_capacity%i==0)
			{
				_capacity++;
				flag=1;
				break;
			}
		}
		if(flag==0&&i==1)
		{
			return _capacity;
		}
	}
}

void HashMap_Destroy(HashMap** _map, void (*_keyDestroy)(void* _key), void (*_valDestroy)(void* _value))
{
	int i;
	ListItr tempItr;
	void* removedData;
	
	if(NULL==(*_map)||NULL==_map||(*_map)->m_magicNumber==DEAD_MAGIC_NUMBER)
	{
		return;
	}
	
	for(i=0;i<(*_map)->m_capacity;i++)
	{
		tempItr=ListItr_Begin((*_map)->m_buckets[i]);
		while(tempItr!=(ListItr_Next(tempItr)))
		{
			removedData=ListItr_Remove(tempItr);
				
			if(NULL!=_valDestroy)
			{
				_keyDestroy(((Pair*)removedData)->m_key);
			}
			
			if(NULL!=_valDestroy)
			{
				_valDestroy(((Pair*)removedData)->m_value);
			}
			free(removedData);
			tempItr=ListItr_Next(tempItr);
		}
		ListDestroy(&(*_map)->m_buckets[i],NULL);
	}
	(*_map)->m_magicNumber=DEAD_MAGIC_NUMBER;
	free(*_map);
	*_map=NULL;
	return;
}

Map_Result HashMap_Rehash(HashMap *_map, size_t _capacity)
{
	size_t newCapacity;
	newCapacity=getPrime(_capacity);
	printf("Old capacity = %ld\n",_capacity);
	printf("New capacity = %ld\n",newCapacity);
	if(_map->m_magicNumber==MAGIC_NUMBER)
	{
		if(NULL==_map)
		{
			return MAP_ALLOCATION_ERROR;
		}
		_map->m_buckets=(List**)realloc(_map->m_buckets,newCapacity*sizeof(List*));
		if(NULL==_map)
		{
			return MAP_ALLOCATION_ERROR;
		}
		_map->m_capacity=newCapacity;
		return MAP_SUCCESS;
	}
	return MAGIC_NUMBER_ERROR;
}

Map_Result HashMap_Insert(HashMap* _map, const void* _key, const void* _value)
{
	size_t indexToInsert;
	Pair* p;
	ListResult err;
	int isUniqueKeyFlag;
	
	if(_map->m_magicNumber!=MAGIC_NUMBER||NULL==_map)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	
	if(NULL==_key)
	{
		return MAP_KEY_NULL_ERROR;
	}
	
	indexToInsert=(_map->m_hashFunc(_key))%(_map->m_capacity);
	isUniqueKeyFlag=isUnique(_map,indexToInsert,_key);
	
	if(0==isUniqueKeyFlag)
	{
			return MAP_KEY_DUPLICATE_ERROR;
	}		
	
	p=PairCreate(_key,_value);
	if(NULL==p)
	{
		return MAP_ALLOCATION_ERROR;
	}	
	
	err=ListPushHead(_map->m_buckets[indexToInsert],p);
	if(LIST_ALLOCATION_ERROR==err)
	{
		return MAP_ALLOCATION_ERROR;
	}

	return MAP_SUCCESS;
}

static Pair* PairCreate(const void *_key,const void* _value)
{
	Pair *p=(Pair*)malloc(1*sizeof(Pair));
	if(NULL==p)
	{
		return NULL;
	}
	p->m_key=(void*)_key;
	p->m_value=(void*)_value;
	return p;
}

static int isUnique(HashMap* _map,size_t indexToInsert,const void* _key)
{
	ListItr li=ListItr_Begin(_map->m_buckets[indexToInsert]);
	Pair* tempKey;
	while(li!=(ListItr_Next(li)))
	{
		tempKey=(Pair*)ListItr_Get(li);
		if(_map->m_equalFunc(tempKey->m_key,_key)==0)
		{
			return 0;
		}
		li=ListItr_Next(li);
	}
	return 1;
}

Map_Result HashMap_Remove(HashMap* _map, const void* _searchKey, void** _pKey, void** _pValue)
{
	int i;
	ListItr temp;
	void* removedData;
	Pair* tempKey;
	if(_map->m_magicNumber==DEAD_MAGIC_NUMBER)
	{	
		return MAGIC_NUMBER_ERROR;
	}	
	
	if(HashMap_Find(_map,_searchKey,_pValue)==MAP_KEY_NOT_FOUND_ERROR)
	{
		return MAP_KEY_NOT_FOUND_ERROR;
	}
	
	for(i=0;i<_map->m_capacity;i++)
	{
		temp=ListItr_Begin(_map->m_buckets[i]);
		while(temp!=(ListItr_Next(temp)))
		{
			tempKey=(Pair*)ListItr_Get(temp);
			if(_map->m_equalFunc(tempKey->m_key,_searchKey)==0)			
			{
				*_pKey=tempKey->m_key;
				*_pValue=tempKey->m_value;					
				removedData=ListItr_Remove(temp);
				temp=ListItr_Next(temp);
				return MAP_SUCCESS;
			}
			temp=ListItr_Next(temp);
		}
	}
	return MAP_SUCCESS;
}

Map_Result HashMap_Find(const HashMap* _map, const void* _searchKey, void** _pValue)
{
	int i;
	ListItr temp;
	Pair* tempKey;
	if(_map->m_magicNumber==MAGIC_NUMBER)
	{	
		for(i=0;i<_map->m_capacity;i++)
		{
			temp=ListItr_Begin(_map->m_buckets[i]);
			while(temp!=(ListItr_Next(temp)))
			{
				tempKey=(Pair*)ListItr_Get(temp);
				if(_map->m_equalFunc(tempKey->m_key,_searchKey))
				{				
					*_pValue=tempKey->m_key;
					return MAP_SUCCESS;
				}		
			}
		}
		return MAP_KEY_NOT_FOUND_ERROR;
	}
	return MAGIC_NUMBER_ERROR;
}

size_t HashMap_Size(const HashMap* _map)
{
	int i;
	int countNodes=0;
	ListItr temp;
	if(_map->m_magicNumber==MAGIC_NUMBER)
	{	
		for(i=0;i<_map->m_capacity;i++)
		{
			temp=ListItr_Begin(_map->m_buckets[i]);
			while(temp!=(ListItr_Next(temp)))
			{
				countNodes++;
				temp=ListItr_Next(temp);
			}
		}
		return countNodes;
	}
	return -1;
}

size_t HashMap_ForEach(const HashMap* _map, KeyValueActionFunction _action, void* _context)
{
	size_t i;
	ListItr temp;
	int countNodes=0;
	if(_map->m_magicNumber==MAGIC_NUMBER)
	{	
		for(i=0;i<_map->m_capacity;i++)
		{
			printf("List number %ld\n",i);
			temp=ListItr_Begin(_map->m_buckets[i]);
			countNodes+=doHashMap_ForEach(temp,_action,_context);
			printf("countNodes = %d\n",countNodes);
			printf("\n\n");
			
		}
		printf("\n");
		return countNodes;
	}
	return -1;	
}

static int doHashMap_ForEach(ListItr _specList,KeyValueActionFunction _action, void* _context)
{
	size_t i=0;
	Pair* tempKey;
	while(_specList!=(ListItr_Next(_specList)))
	{
		tempKey=(Pair*)ListItr_Get(_specList);	
		if(_action(tempKey->m_key,tempKey->m_value,_context)==0)
		{
			printf("inccccccccccccccccccc\n");
			return ++i;
		}
		_specList=ListItr_Next(_specList);
		i++;
	}
	return i;
}

/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: vectorGeneric code
* 						DATE: 22-07-2019 12:07:23
*******************************************************************************/

#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include "vectorGeneric.h"

struct Vector
{
    void**  m_items;
    size_t  m_originalSize;   /* original allocated space for items*/
    size_t  m_size;              /* actual allocated space for items*/
    size_t  m_nItems;        /* actual number of items */
    size_t  m_blockSize;   /* the chunk size to be allocated when no space*/
    int magicNumber;
};


static Vector* resizeUp (Vector* _vector);
Vector* VectorCreate (size_t _initialSize, size_t _extensionBblockSize)
{
	Vector *v;
	v=(Vector*)malloc(1*sizeof(Vector));
	if(!v)
	{
		printf("Allocation failure\n");
		return NULL;
	}
	v->m_items=(void**)malloc(_initialSize*sizeof(void*));
	if(!v->m_items)
	{
		free(v);
		printf("Allocation failure\n");
		return NULL;
	}
	v->m_originalSize=_initialSize;
	v->m_size=v->m_originalSize;
	v->m_nItems=0;
	v->m_blockSize=_extensionBblockSize;
	v->magicNumber=123456789;
	return v;
}

static Vector* resizeUp (Vector* _vector)
{
	
	if(_vector->magicNumber==123456789)
	{
		if(NULL==_vector)
			{
				printf("Vector is not initiallized\n");
				return NULL;
			}
		_vector->m_items=(void**)realloc(_vector->m_items,
		sizeof(_vector->m_items)+(_vector->m_blockSize));
				
		if(NULL==_vector->m_items)
		{
				free(_vector);
				printf("Allocation failure\n");
				return NULL;
		}
		else
		{
			printf("Realloced\n");
			_vector->m_size+=_vector->m_blockSize;
			return _vector;
		}
	}
	else
	{
		return NULL;
	}
}	

void VectorDestroy(Vector** _vector, void (*_elementDestroy)(void* _item))
{
	int i;
	if((*_vector)->magicNumber==123456789)
	{
		if(NULL==*_vector||NULL==_vector)
		{
			printf("Vector is not initiallized\n");
			return;
		}	
		
		for(i=0;i< (*_vector)->m_nItems;i++)
		{
			printf("i=%d\n",i);
			_elementDestroy((*_vector)->m_items[i]);
		}
		(*_vector)->magicNumber=0;
		free(*_vector);
		_vector=NULL;
	}
	return;
}

Vector_Result VectorAppend(Vector* _vector, void* _item)
{
	if(_vector->magicNumber==123456789)
	{
		if(NULL==_vector)
		{
			printf("Vector is not initiallized\n");
			return VECTOR_UNITIALIZED_ERROR;
		}
		
		if(_vector->m_nItems>=_vector->m_size)
		{
			resizeUp(_vector);
			(_vector->m_items)[_vector->m_nItems]=_item;
			_vector->m_nItems++;
		}
		else
		{
			(_vector->m_items)[_vector->m_nItems]=_item;
			_vector->m_nItems++;
		}
	}
	else
	{
		return VECTOR_UNITIALIZED_ERROR;
	}
	return VECTOR_SUCCESS;
}	

Vector_Result VectorRemove(Vector* _vector, void** _pValue)
{
	if(_vector->magicNumber==123456789)
	{	
		if(NULL==_vector)
		{
			return VECTOR_UNITIALIZED_ERROR;
		}
		*_pValue=(_vector->m_items)[_vector->m_nItems-1];
		_vector->m_nItems--;
		/*if(_vector->m_nItems < _vector->m_size)
		{
			resizeDown(_vector);
		}*/
		return VECTOR_SUCCESS;
	}
	else
	{
		return VECTOR_UNITIALIZED_ERROR;
	}
}

Vector_Result VectorGet(const Vector* _vector, size_t _index, void** _pValue)
{
	if(_vector->magicNumber==123456789)
	{	
		if(NULL==_vector)
		{
			return VECTOR_UNITIALIZED_ERROR;
		}
		*_pValue=(_vector->m_items)[_index];
		return VECTOR_SUCCESS;
	}
	else
	{
		return VECTOR_UNITIALIZED_ERROR;
	}
}
	
Vector_Result VectorSet(Vector* _vector, size_t _index, void*  _value)
{
	if(_vector->magicNumber==123456789)
	{	
		if(NULL==_vector)
		{
			return VECTOR_UNITIALIZED_ERROR;
		}	
		(_vector->m_items)[_index]=_value;
	}
	else
	{
		return VECTOR_UNITIALIZED_ERROR;
	}
	return VECTOR_SUCCESS;
}

size_t VectorCapacity(const Vector* _vector)
{
	/*if(_vector->magicNumber==123456789)*/
	{	
		return _vector->m_nItems;
	}
	return -1;	
}

void printPrintGeneral(Vector* _vector,void (*print)(void* _element))
{
	int i;
	for(i=0;i< _vector->m_nItems;i++)
	{
		printf("i=%d\n",i);
		print(_vector->m_items[i]);
	}
}
void printInt(void* _item)
{
	printf("%d\n",*(int*)_item);
}

void printPerson(void* _item)
{
/*	printf("%d\n",*(Person*		(_item->m_id)	)	);*/
}


size_t VectorForEach(const Vector* _vector, VectorElementAction _action, void* _context)
{
	if(_vector->magicNumber==123456789)
	{
		int i=0;
		if(NULL== _vector)
		{
			return 0;
		}
		for (i=0;i<_vector->m_nItems;i++)
		{
			if(_action(_vector->m_items[i],i,_context)==0)
			{
				return ++i;
			}
		}
		return i;
	}
return 0;
}

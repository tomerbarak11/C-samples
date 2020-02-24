#include "vector.h"
struct Vector
{
    int*    m_items;
    size_t  m_originalSize;   /* original allocated space for items*/
    size_t  m_size;              /* actual allocated space for items*/
    size_t  m_nItems;        /* actual number of items */
    size_t  m_blockSize;   /* the chunk size to be allocated when no space*/
};

Vector* resize (Vector* _vector)
{
	if(NULL==_vector)
		{
			printf("vector is not initiallized\n");
			return NULL;
		}
			_vector->m_items=(int*)realloc(_vector->m_items,
			sizeof(_vector->m_items)+(_vector->m_blockSize));
			
	if(NULL==_vector->m_items)
	{
			free(_vector);
			printf("allocation failure\n");
			return NULL;
	}
	else
	{
		printf("did realloced\n");
		_vector->m_size+=_vector->m_blockSize;
		return _vector;
	}
}

Vector* VectorCreate (size_t _initialSize, size_t _extensionBblockSize)
{
	Vector *v;
	v=(Vector*)malloc(1*sizeof(Vector));
	if(!v)
	{
		printf("allocation failure\n");
		return NULL;
	}
	v->m_items=(int*)malloc(_initialSize*sizeof(int));
	if(!v->m_items)
	{
		free(v);
		printf("allocation failure\n");
		return NULL;
	}
	v->m_originalSize=_initialSize;
	v->m_size=v->m_originalSize;
	v->m_nItems=0;
	v->m_blockSize=_extensionBblockSize;

	return v;
}

void VectorDestroy (Vector* _vector)
{
	free(_vector);
}

ADTErr VectorAdd (Vector *_vector, int _item)
{
	if(NULL==_vector)
	{
		printf("vector is not initiallized\n");
		return ERR_NOT_INITIALIZED;
	}
	
	if(_vector->m_nItems>=_vector->m_originalSize)
	{
		printf("resizing\n");
		resize(_vector);
		(_vector->m_items)[_vector->m_nItems]=_item;
		_vector->m_nItems++;
	}
	else
	{
		(_vector->m_items)[_vector->m_nItems]=_item;
		_vector->m_nItems++;
	}
	return ERR_OK;
}

ADTErr VectorDelete (Vector *_vector,  int* _item)
{
	*_item=(_vector->m_items)[_vector->m_nItems];
	(_vector->m_items)[_vector->m_nItems]=-999;
	_vector->m_nItems--;
	return ERR_OK;
}

ADTErr VectorGet(Vector *_vector, size_t _index, int *_item)
{
	*_item=(_vector->m_items)[_index];
	return ERR_OK;
}

ADTErr VectorSet(Vector *_vector, size_t _index, int  _item)
{
	(_vector->m_items)[_index]=_item;
	return ERR_OK;
}

ADTErr VectorItemsNum(Vector *_vector, int*  _numOfItems)
{
	*_numOfItems=_vector->m_nItems;
	return ERR_OK;
}

void VectorPrint(Vector *_vector)
{
	int i;
	if(_vector->m_nItems==0)
	{
		printf("vector is empty\n");
	}
	else
	{
		for(i=0;i<_vector->m_nItems;i++)
		{
			printf("item number %d = %d\n",i,_vector->m_items[i]);
		}
	}
}

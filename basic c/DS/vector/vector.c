#include "vector.h"
struct Vector
{
    int*    m_items;
    size_t  m_originalSize;   /* original allocated space for items*/
    size_t  m_size;              /* actual allocated space for items*/
    size_t  m_nItems;        /* actual number of items */
    size_t  m_blockSize;   /* the chunk size to be allocated when no space*/
};

Vector* resizeUp (Vector* _vector)
{
	if(NULL==_vector)
		{
			printf("Vector is not initiallized\n");
			return NULL;
		}
			_vector->m_items=(int*)realloc(_vector->m_items,
			sizeof(_vector->m_items)+(_vector->m_blockSize));
			
	if(NULL==_vector->m_items)
	{
			free(_vector);
			printf("Allocation failure\n");
			return NULL;
	}
	else
	{
		printf("Did realloced\n");
		_vector->m_size+=_vector->m_blockSize;
		return _vector;
	}
}


Vector* resizeDown (Vector* _vector)
{
	if(NULL==_vector)
		{
			printf("Vector is not initiallized\n");
			return NULL;
		}
			_vector->m_items=(int*)realloc(_vector->m_items,
			sizeof(_vector->m_items)-1);
			
	if(NULL==_vector->m_items)
	{
			free(_vector);
			printf("Allocation failure\n");
			return NULL;
	}
	else
	{
		printf("Did realloced down\n");
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
		printf("Allocation failure\n");
		return NULL;
	}
	v->m_items=(int*)malloc(_initialSize*sizeof(int));
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
		printf("Vector is not initiallized\n");
		return ERR_NOT_INITIALIZED;
	}
	
	if(_vector->m_nItems>=_vector->m_size)
	{
		printf("Resizing\n");
		resizeUp(_vector);
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
	/*if(_vector->m_nItems < _vector->m_size)
	{
		resizeDown(_vector);
	}*/
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
	int i,num;
	if(_vector->m_nItems==0)
	{
		printf("Vector is empty\n");
	}
	else
	{
		for(i=0;i<_vector->m_nItems;i++)
		{	
			VectorGet(_vector,i,&num);
			printf("Item %d = ",num);
			printOneElement(num);

		}
	}
}

void printOneElement(int num)
{
		switch(num)
			{
				/*Hearts 0-12*/
				case 0 ... 8:
							printf("\xE2\x99\xA5 %d\n",num%13+2);
							break;																				
				case 9:
							printf("\xE2\x99\xA5 J\n");
							break;	
				case 10:
							printf("\xE2\x99\xA5 Q\n");
							break;			
				case 11:
							printf("\xE2\x99\xA5 K\n");
							break;	
				case 12:
							printf("\xE2\x99\xA5 A\n");
							break;			
				/*Clubs 13-25*/
				case 13 ... 21:
							printf("\xE2\x99\xA0 %d\n",num%13+2);
							break;
				case 22:
							printf("\xE2\x99\xA0 J\n");
							break;
				case 23:
							printf("\xE2\x99\xA0 Q\n");
							break;							
				case 24:
							printf("\xE2\x99\xA0 K\n");
							break;					
				case 25:
							printf("\xE2\x99\xA0 A\n");
							break;
				/*Diamonds 26-38*/	
				case 26 ... 34:
							printf("\xE2\x99\xA6 %d\n",num%13+2);
							break;
				case 35:
							printf("\xE2\x99\xA6 J\n");
							break;	
				case 36:
							printf("\xE2\x99\xA6 Q\n");
							break;							
				case 37:
							printf("\xE2\x99\xA6 K\n");
							break;	
				case 38:
							printf("\xE2\x99\xA6 A\n");
							break;
				/*Clubs 39-51*/								
				case 39 ... 47:
							printf("\xE2\x99\xA3 %d\n",num%13+2);
							break;
				case 48:
							printf("\xE2\x99\xA3 J\n");
							break;	
				case 49:
							printf("\xE2\x99\xA3 Q\n");
							break;							
				case 50:
							printf("\xE2\x99\xA3 K\n");
							break;	
				case 51:
							printf("\xE2\x99\xA3 A\n");
							break;					
				default:
						break;
			}
}

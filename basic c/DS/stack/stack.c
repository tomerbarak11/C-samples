#include "stack.h"

struct Stack
{
	Vector *vector;
};

stack* stackCreate(size_t _size,size_t _blockSize)
{
	stack *v;
	v=(stack->*vector)malloc(1*sizeof(stack->vector));
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

void stackDestroy(stack* _vector)
{
	free(_vector);
}

ADTErr* stackPush(stack* _vector,int _item)
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
		(_vector->m_items)[_vector->m_nItems+1]=_item;
		_vector->m_nItems++;
	}
	else
	{
		(_vector->m_items)[_vector->m_nItems+1]=_item;
		_vector->m_nItems++;
	}

	return ERR_OK;
}

ADTErr* stackPop(stack* _vector,int* _item)
{
	_item=(_vector->m_items)[_vector->m_nItems];
	(_vector->m_items)[_vector->m_nItems]=-999;
	_vector->m_nItems--;
	return ERR_OK;
}

ADTErr* stackTop (stack* _stack,int* _item)
{
	
}
int stackisEmpty(stack* _stack)
{

}
void stackPrint(stack* _stack)
{

}

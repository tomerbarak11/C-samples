#include "stack.h"
#include "vector.h"

struct stack
{
	Vector *vector;
};

stack* stackCreate(size_t _size,size_t _blockSize)
{
	stack* s;
	s=(stack*)malloc(1*sizeof(stack));
	if(NULL==s)
	{
		printf("allocation failure\n");
		return NULL;
	}
	s->vector= VectorCreate (_size, _blockSize);
	return s;
}

void stackDestroy(stack* _vector)
{
	VectorDestroy(_vector);
}

ADTErr stackTop(stack* _vector,int *_item)
{
	VectorAdd(_vector,_item);
	return ERR_OK;
}

ADTErr stackPop(stack* _vector,int* _item)
{
	VectorDelete(_vector,_item);
	return ERR_OK;
}

int stackisEmpty(stack* _stack)
{

}
void stackPrint(stack* _vector)
{
	VectorPrint(_vector->vector);
}

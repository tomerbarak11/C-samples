/** 
 *  @author Tomer Barak
 *
 *  @bug No known bugs.
 */

#ifndef _stack_h_
#define _stack_h_
#include <stdio.h>
#include <stdlib.h>
#include "ADTDefs.h"
#include "vector.h"

typedef struct stack stack;

stack* stackCreate(size_t _size,size_t _blockSize);
void stackDestroy(stack* _vector);
ADTErr stackPush(stack* _vector,int _item);
ADTErr stackPop(stack* _vector,int* _item);
ADTErr stackTop(stack* _vector,int* _item);
int stackisEmpty(stack* _vector);
void stackPrint(stack* _vector);

#endif

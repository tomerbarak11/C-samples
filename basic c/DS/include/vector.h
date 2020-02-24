/** 
 *  @author Tomer Barak
 *
 *  @bug No known bugs.
 */

#ifndef _vector_h_
#define _vector_h_
#include <stdio.h>
#include <stdlib.h>
#include "ADTDefs.h"

typedef struct Vector Vector;

Vector* VectorCreate (size_t _initialSize, size_t _extensionBblockSize);
/*
 * @params _vector create vector
*/
void     VectorDestroy (Vector* _vector);
/*
 * @params _vector destroy vector
*/
ADTErr   VectorAdd (Vector *_vector,  int  _item);
/*
 * @params _vector add item to vector
*/
ADTErr   VectorDelete (Vector *_vector, int* _item);
/*
 /* @params _vector delete last item from vector *
*/
ADTErr VectorGet(Vector *_vector, size_t _index, int *_item);
/*
 * @params _vector get an item of users index from vector
*/
ADTErr   VectorSet(Vector *_vector, size_t _index, int  _item);
/*
 * @params _vector sets an item to users index in vector
*/
ADTErr   VectorItemsNum(Vector *_vector, int*  _numOfItems);
/*
 * @params _vector counts number of elements in vector
*/
void VectorPrint(Vector *_vector);
/*
 * @params _vector prints all items in vector
*/
Vector* resize (Vector* _vector);
/*
 * @params _vector if vector is full, increases size of vector
*/

#endif

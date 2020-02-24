/**************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: heap header
* 						DATE: 10-07-2019 17:40:03
*******************************************************************************/

#ifndef __HEAP_H__
#define __HEAP_H__


#include <stddef.h>
#include "vector.h"


typedef struct Heap Heap;

/**@Description: builds heap from vector
 * @params _x : vector pointer
 * @returns: heap
 */
Heap* HeapBuild(Vector* _vec);

/**@Description: destroys heap 
 * @params _x : vector pointer
 * @returns:
 */
void HeapDestroy(Heap* _heap);

/**@Description: inserts new data to heap
 * @params _x : original heap pointer and data
 * @returns: ERR_NOT_INITIALIZED if is NULL and ERR_OK if not null
 */
ADTErr HeapInsert(Heap* _heap,int data);

/**@Description: puts first data in vector[0] which is maximum into data
 * @params _x : heap pointer and NULL data
 * @returns: ERR_NOT_INITIALIZED if is NULL and ERR_OK if not null
 */
ADTErr HeapMax(Heap* _heap,int* data);

/**@Description: removes first data in vector[0] which is maximum into data, puts vector[0] there and rebuild the heap, puts vector[0] in data
 * @params _x : heap pointer and NULL data
 * @returns: ERR_NOT_INITIALIZED if is NULL and ERR_OK if not null
 */
ADTErr HeapExtractMax(Heap* _heap,int* data);

/**@Description: counts number of items in heap
 * @params _x : heap pointer
 * @returns:
 */
int HeapItemsNum(Heap* _heap);

void HeapPrint(Heap* _heap);
void Heapsort(Heap* _heap);
#endif


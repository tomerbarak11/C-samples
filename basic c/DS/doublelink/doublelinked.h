/**************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: doublelinked header
* 						DATE: 02-07-2019 16:18:05
*******************************************************************************/

#ifndef __DOUBLELINKED_H__
#define __DOUBLELINKED_H__
#include <stddef.h>
#include "ADTDefs.h"

/**@Description:
 * Average time complexity :
 * Worst : 
 * @params _x :
 * @returns:
 */

typedef struct Node Node;
typedef struct List List;

List* ListCreate();
void ListDestroy(List* _list);

ADTErr ListPushHead(List* _list,int data);
ADTErr ListPushTail(List* _list,int data);
ADTErr ListPopHead(List* _list,int* data);
ADTErr ListPopTail(List* _list,int* data);
size_t ListCountItems(List* _list);
int ListIsEmpty(List* _list);
void PrintList(List* _list);
#endif          /* doublelinked s*/





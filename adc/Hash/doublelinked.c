/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: doublelinked code
* 						DATE: 02-07-2019 16:18:05
*******************************************************************************/

#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc(List) */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include "list.h"
#include "list_itr.h" 

struct Node{
	void* m_data;
	Node* m_next;
	Node* m_prev;
};

struct List
{
	int m_magicNumber;
	Node m_head;
	Node m_tail;
};

static ListItr CreateNode(void* _element);
static size_t ListCountItemsWithRange(ListItr _begin,ListItr _end);
List* ListCreate()
{
	List *l=(List*)malloc(1*sizeof(List));
	if(NULL==l)
	{
		return NULL;
	}
	(l->m_head).m_next=&l->m_tail;
	(l->m_head).m_prev=NULL;
	
	(l->m_tail).m_prev=&l->m_head;
	(l->m_tail).m_next=NULL;
	l->m_magicNumber=123456789;
	return l;
}

void ListDestroy(List** _pList, void (*_elementDestroy)(void* _item))
{
	Node* temp;
	if(NULL==*_pList||NULL==_pList)
	{
		return;
	}
	temp=(*_pList)->m_head.m_next;
	while(NULL!=temp->m_next)
	{
		_elementDestroy(temp->m_data);
		temp=temp->m_next;
		free(temp->m_prev);

	}
	free(*_pList);
	*_pList=NULL;
	return;
}

void itemDestroy(void* _temp)
{
		free(_temp);	
}

ListResult ListPushHead(List* _list, void* _item)
{
	Node *n=(Node*)malloc(1*sizeof(Node));
	if(NULL==n)
	{
		return LIST_ALLOCATION_ERROR;
	}

	n->m_next=_list->m_head.m_next;
	_list->m_head.m_next=n;
	
	n->m_next->m_prev=n;
	n->m_prev=&_list->m_head;
	
	n->m_data=_item;
	return LIST_SUCCESS;
}

ListResult ListPushTail(List* _list, void* _item)
{
	Node *n=(Node*)malloc(1*sizeof(Node));
	if(NULL==n)
	{
		return LIST_ALLOCATION_ERROR;
	}
	n->m_data=_item;
	
	n->m_prev=_list->m_tail.m_prev;
	_list->m_tail.m_prev=n;
	
	n->m_prev->m_next=n;
	n->m_next=&_list->m_tail;
	return LIST_SUCCESS;
}

ListResult ListPopHead(List* _list, void** _pItem)
{
	Node *n;
	if(_list->m_head.m_next==&_list->m_tail)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	n=_list->m_head.m_next;
	_list->m_head.m_next=_list->m_head.m_next->m_next;
	_list->m_head.m_next->m_prev=&_list->m_head;
	
	n->m_next=NULL;
	n->m_prev=NULL;
	*_pItem=n->m_data;
	free(n);
	return LIST_SUCCESS;
}

ListResult ListPopTail(List* _list, void** _pItem)
{
	Node *n;
	if(_list->m_head.m_next==&_list->m_tail)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	n=_list->m_tail.m_prev;
	_list->m_tail.m_prev=_list->m_tail.m_prev->m_prev;
	_list->m_tail.m_prev->m_next=&_list->m_tail;
	n->m_next=NULL;
	n->m_prev=NULL;
	*_pItem=n->m_data;
	free(n);
	return LIST_SUCCESS;
}

size_t ListCountItems(List* _list)
{
	unsigned long int i=0;
	while(_list->m_head.m_next!=&_list->m_tail)
	{
		i++;
		_list->m_head.m_next=_list->m_head.m_next->m_next;
	}
	return i;
}

static size_t ListCountItemsWithRange(ListItr _begin,ListItr _end)
{
	unsigned long int countNodes=0;
	while(((Node*)_begin)->m_next!=(Node*)_end)
	{
		countNodes++;
		/*(Node*)_begin=((Node*)_begin)->m_next;*/
	}
	return countNodes;
}

size_t DLLForEach( List* _l, DLLElementAction _action, void* _context)
{
	size_t size=ListCountItems(_l);
	int i;
	printf("\n\nsize= %ld\n",size);
	Node* temp=&_l->m_head;
	if(NULL!=temp->m_next)
	{
		temp=temp->m_next;
	}
	
	if(_l->m_magicNumber==123456789)
	{
		i=0;
		if(NULL== _l)
		{
			return 0;
		}
		for (i=0;i<size;i++)
		{
			if(_action(temp->m_data,i,_context)==0)
			{
				printf("i=%d\n",i);
				return ++i;
			}
		}
		return i;
	}
	return 0;
}

void printList(List* _l,DLLElementAction _action)
{
	size_t i=1;
	Node* n=_l->m_head.m_next;
	while(NULL!=n)
	{
		_action(n->m_data,i,NULL);

		n=n->m_next;
		i++;
	}
}

ListItr ListItr_Begin(const List* _list)
{
	return (ListItr)((_list->m_head).m_next);	
}

ListItr ListItr_End(const List* _list)
{
	return (ListItr)((&_list->m_tail));	
}

int ListItr_Equals(const ListItr _a, const ListItr _b)
{
	if((ListItr)_a==(ListItr)_b)
	{
		return 1;
	}
	return 0;	
}

ListItr ListItr_Next(ListItr _itr)
{
	if(NULL==(ListItr)(((Node*)_itr)->m_next))
	{
		return (ListItr)(((Node*)_itr));
	}
	return (ListItr)(((Node*)_itr)->m_next);
}

ListItr ListItr_Prev(ListItr _itr)
{
	if(NULL==(ListItr)(((Node*)_itr)->m_prev))
	{
		return (ListItr)(((Node*)_itr));
	}
	return (ListItr)(((Node*)_itr)->m_prev);
}

void* ListItr_Get(ListItr _itr)
{
	return (ListItr)(((Node*)_itr)->m_data);
}

void* ListItr_Set(ListItr _itr, void* _element)
{
	void* temp=((Node*)_itr)->m_data;
	((Node*)_itr)->m_data=_element;
	return temp;
}

ListItr ListItr_InsertBefore(ListItr _itr, void* _element)
{
	ListItr temp=CreateNode(_element);
	((Node*)temp)->m_next=(Node*)_itr;
	((Node*)temp)->m_prev=((Node*)_itr)->m_prev;
	((Node*)_itr)->m_prev=((Node*)temp);
	((Node*)_itr)->m_prev->m_next=((Node*)temp);
}

static ListItr CreateNode(void* _element)
{
	Node* temp;
	ListItr li;
	temp=(Node*)malloc(1*sizeof(Node));
	if(NULL==temp)
	{
		return NULL;	
	}
	temp->m_next=NULL;
	temp->m_prev=NULL;
	li=(ListItr)temp;
	return li;
}

void* ListItr_Remove(ListItr _itr)
{
	
	/*empty list
	if((List)_itr->m_next==(List)(_itr->m_tail)) &&(List)_itr->m_prev==NULL)
	{
		return NULL;
	}*/
	((Node*)_itr)->m_prev->m_next=((Node*)_itr)->m_next;
	((Node*)_itr)->m_next->m_prev=((Node*)_itr)->m_prev;
	((Node*)_itr)->m_next=NULL;
	((Node*)_itr)->m_prev=NULL;
	free(_itr);
}

ListItr ListItr_ForEach(ListItr _begin, ListItr _end, ListActionFunction _action, void* _context)
{
	int i=0;
	Node* temp=(Node*)&_begin;
	if(NULL!=temp->m_next)
	{
		temp=temp->m_next;
	}
	/*if(NULL== _l)
	{
		return 0;
	}
	while(temp!=_end)
	{
		if(_action(temp->m_data,i,_context)==0)
		{
			return ++i;
		}
		temp=temp->next;
	}	
	return 0;*/
}

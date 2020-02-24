/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: doublelinked code
* 						DATE: 02-07-2019 16:18:05
*******************************************************************************/

#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include "doublelinked.h"

struct Node{
	int m_data;
	Node* m_next;
	Node* m_prev;
};

struct List
{
	Node m_head;
	Node m_tail;
};

List* ListCreate()
{
	List *l=(List*)malloc(1*sizeof(List));
	(l->m_head).m_next=&l->m_tail;
	(l->m_head).m_prev=NULL;
	
	(l->m_tail).m_prev=&l->m_head;
	(l->m_tail).m_next=NULL;
	return l;
}

void ListDestroy(List* _list)
{
	Node curr=_list->m_head;
}

ADTErr ListPushHead(List* _list,int data)
{
	Node *n=(Node*)malloc(1*sizeof(Node));
	if(NULL==n)
	{
		return ERR_ALLOCATION_FAILED;
	}

	n->m_next=_list->m_head.m_next;
	_list->m_head.m_next=n;
	
	n->m_next->m_prev=n;
	n->m_prev=&_list->m_head;
	
	n->m_data=data;
	printf("%d	%d\n",data,n->m_data);
	return ERR_OK;
}

ADTErr ListPushTail(List* _list,int data)
{
	Node *n=(Node*)malloc(1*sizeof(Node));
	if(NULL==n)
	{
		return ERR_ALLOCATION_FAILED;
	}
	n->m_data=data;
	
	n->m_prev=_list->m_tail.m_prev;
	_list->m_tail.m_prev=n;
	
	n->m_prev->m_next=n;
	n->m_next=&_list->m_tail;
	return ERR_OK;
}

ADTErr ListPopHead(List* _list,int* data)
{
	Node *n;
	if(_list->m_head.m_next==&_list->m_tail)
	{
		return ERR_UNDERFLOW;
	}
	n=_list->m_head.m_next;
	_list->m_head.m_next=_list->m_head.m_next->m_next;
	_list->m_head.m_next->m_next->m_prev=&_list->m_head;
	
	n->m_next=NULL;
	n->m_prev=NULL;
	*data=n->m_data;
	free(n);
	return ERR_OK;
}

ADTErr ListPopTail(List* _list,int* data)
{
	Node *n;
	if(_list->m_head.m_next==&_list->m_tail)
	{
		return ERR_UNDERFLOW;
	}
	n=_list->m_tail.m_prev;
	_list->m_tail.m_prev=_list->m_tail.m_prev->m_prev;
	_list->m_tail.m_prev->m_prev->m_next=&_list->m_tail;
	n->m_next=NULL;
	n->m_prev=NULL;
	*data=n->m_data;
	free(n);
	return ERR_OK;
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

int ListIsEmpty(List* _list)
{
	if(_list->m_head.m_next==&_list->m_tail)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void PrintList(List* _list)
{
	int i=1;
	while(_list->m_head.m_next!=&_list->m_tail)
	{
		printf("node number %d = %d\n",i,_list->m_head.m_next->m_data);
		i++;
		_list->m_head.m_next=_list->m_head.m_next->m_next;
	}
	if (i==1)
	{
		printf("list is empty\n");
	}
}

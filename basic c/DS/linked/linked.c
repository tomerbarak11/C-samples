/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: linked code
* 						DATE: 01-07-2019 15:11:38
*******************************************************************************/
#include "linked.h"
person* ListInsertHead(person* _head,person* _p)
{
	if(NULL==_head)
	{
		_head=_p;
		return _head;
	}
	else
	{
		_p->m_next=_head;
		return _p;
	}
}
person* ListRemoveHead(person* _head,person** _item)
{
	person *temp;
	if(!_head)
	{
		printf("error the list is empty\n");
		*_item=NULL;
		return NULL;
	}
	*_item=_head;
	temp=_head->m_next;
	_head=temp;
	return _head;
}
person* ListInsertByKey(person* _head,int _key,person* _p)
{	
	person *temp=_head;
	while(NULL!=temp)
	{	
		if(_p->m_id > temp->m_id)
		{
			if(NULL==temp->m_next)
			{
				temp->m_next=_p;
			}
			else if(NULL!=temp->m_next)
			{	
				temp->m_next=_p;
				return _head;
			}
		}
		else if (_p->m_id < temp->m_id)
		{
			_head=ListInsertHead(_head,_p);
			return _head;
		}
		temp=temp->m_next;
	}
	return _head;
}
person* ListInsertByKeyRec(person* _head,int _key,person* _p)
{
	if(NULL==_p)
	{
		return _head;
	}
	if(NULL==_head||_head->m_id>_key)
	{
		_p->m_next=_head;
		return _p;
	}
		if(_head->m_id==_key)
	{
		return _head;
	}
	_head->m_next=ListInsertByKeyRec(_head->m_next,_key,_p);
}
person* ListRemoveByKey(person* _head,int _key,person** _p)
{
	person* todel=_head;
	if(NULL==_head)
	{
		return NULL;
	}
	while(NULL!=todel->m_next)
	{
		if(todel->m_next->m_id==_key)
		{
			if(NULL!=_p)
			{
				*_p=todel->m_next;
			}
			todel->m_next=todel->m_next->m_next;
		}
		todel=todel->m_next;
	}
	return _head;
}
person* ListRemoveByKeyRec(person* _head,int _key,person** _p)
{
	if(NULL==_head)
	{
		return NULL;
	}
	if(_head->m_id==_key)
	{
		if(NULL!=_p)
		{
		*_p=_head;
		}
		return _head->m_next;
	}
	_head->m_next=ListRemoveByKeyRec(_head->m_next,_key,_p);
}

void PrintList(person* _head)
{
	int i=1;
	while(NULL!=_head)
		{
			printf("person number %d\n",i);
			i++;
			printf("id = %d\n",_head->m_id);
			printf("name = %s\n",_head->m_name);
			printf("age = %d\n\n",_head->m_age);
			_head=_head->m_next;
		}
}

void PrintLastRec(person* _head)
{
	if(NULL==_head)
	{
		printf("empty list\n");
	}
	if(_head->m_next!=NULL)
	{
			printf("last");
			printf("id = %d\n",_head->m_id);
			printf("name = %s\n",_head->m_name);
			printf("age = %d\n\n",_head->m_age);
	}
	PrintLastRec(_head->m_next);
}

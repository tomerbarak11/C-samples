/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: tree code
* 						DATE: 10-07-2019 11:16:03
*******************************************************************************/

#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include "tree.h"

static int checkFullTree(Node* _node);
static int checkSimilarTree(Node* _n1,Node* _n2);
static int checkPerfectTree(Node* _node);
static void createMirrorTree(Node* _node);

struct Node{
	int m_data;
	Node *m_right,*m_left,*m_father;
};

struct Tree{
	Node* m_root;	
};

Tree* TreeCreate()
{
	Tree* root;
	root=(Tree*)malloc(1*sizeof(Tree));
	root->m_root=NULL;
	return root;
}

void TreeDestroy(Tree* _tree)
{
	if(NULL==_tree)
	{
		return;
	}
	destroyTreeSubtree(_tree->m_root);
	free(_tree);
	return;
}

void destroyTreeSubtree(Node* _n)
{
	if(NULL==_n)
	{
		return;
	}
	
	destroyTreeSubtree(_n->m_left);
	destroyTreeSubtree(_n->m_right);
	_n->m_left=NULL;
	_n->m_right=NULL;
	free(_n->m_left);
	free(_n->m_right);
	free(_n);
}

ADTErr TreeInsert(Tree* _tree,int _data)
{
	Node* new;
	Node* temp;

	if(NULL==_tree)
	{
		return ERR_NOT_INITIALIZED;
	}
	
	if(NULL==_tree->m_root)
	{
		new=createNode(_data);
		_tree->m_root=new;
		return ERR_OK;
	}
	temp=_tree->m_root;
	
	while(temp->m_left||temp->m_right)
	{
		if(_data>temp->m_data)
		{	
			if(NULL==temp->m_right)
			{
				new=createNode(_data);
				temp->m_right=new;
				return ERR_OK;
			}
			temp=temp->m_right;
		}
		else if(_data<temp->m_data)
		{
			if(NULL==temp->m_left)
			{
				new=createNode(_data);
				temp->m_left=new;
				return ERR_OK;
			}
			temp=temp->m_left;
		}
		else
		{
			return ERR_OK;
		}
	}
	new=createNode(_data);
	if(_data<temp->m_data)
	{
		temp->m_left=new;
		return ERR_OK;
	}

	else if(_data>temp->m_data)
	{
		temp->m_right=new;
		return ERR_OK;
	}
	else
	{
		return ERR_OK;
	}
}

int TreeIsDataFound (Tree* _tree,int _data)
{
	Node* temp=_tree->m_root;
	while(temp)
	{
		if(_data<temp->m_data)
		{	
			temp=temp->m_left;
		}
		else if(_data>temp->m_data)
		{	
			temp=temp->m_right;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

void TreePrint(Tree* _tree,TreeTraverse _traverseMode)
{
	if(NULL==_tree)
	{
		printf("empty tree");
		return;
	}
	switch(_traverseMode)
	{
		case PRE_ORDER:
				printPreorder(_tree->m_root);
				break;
		case IN_ORDER:				
				printInorder(_tree->m_root);
				break;
		case POST_ORDER:
				printPostorder(_tree->m_root);
				break;	
		default:
				break;							
	}
}

Node* createNode(int _data)
{
	Node* new;
	new=(Node*)malloc(1*sizeof(Node));
	if(NULL==new)
	{
		printf("allocation fail\n");
		return NULL;
	}
	new->m_data=_data;
	new->m_right=NULL;
	new->m_left=NULL;
	return new;
}

void printPreorder(Node* _node)
{
	if(_node)
	{
		printf("%d ",_node->m_data);
		printInorder(_node->m_left);
		printInorder(_node->m_right);
	}
	return;
}

void printInorder(Node* _node)
{
	if(_node)
	{
		printInorder(_node->m_left);
		printf("%d ",_node->m_data);
		printInorder(_node->m_right);
	}
	return;
}

void printPostorder(Node* _node)
{
	if(_node)
	{
		printPostorder(_node->m_left);
		printPostorder(_node->m_right);
		printf("%d ",_node->m_data);
	}
	return;
}

int isFullTree(Tree* _tree)
{
	int res;
	if(!_tree)
	{
		return 1;
	}
	res=checkFullTree(_tree->m_root);
}

static int checkFullTree(Node* _node)
{
	if(NULL==_node)
	{
		return 1;
	}
	
	if(NULL==_node->m_left && NULL==_node->m_right)
	{
		return 1;
	}
	
	if(NULL!=_node->m_left && NULL!=_node->m_right)
	{
		return (checkFullTree(_node->m_left) && checkFullTree(_node->m_right));
	}
	return 0;
}

/*=================================================================*/
int isSimilarTree(Tree* _tree1,Tree* _tree2)
{
	int res;
	if(NULL==_tree1&&NULL==_tree2)
	{
		return 1;
	}
	res=checkSimilarTree(_tree1->m_root,_tree2->m_root);
}

static int checkSimilarTree(Node* _n1,Node* _n2)
{
	if(NULL==_n1&&NULL==_n2)
	{
		return 1;
	}
	
	if(NULL==_n1&&NULL!=_n2)
	{
		return 0;
	}
	
	if(NULL!=_n1&&NULL==_n2)
	{
		return 0;
	}
	/*===============================================================*/
	if(NULL==_n1->m_left && NULL==_n2->m_left
		&&NULL==_n1->m_right && NULL==_n2->m_right)
	{
		return 1;
	}
	/*===============================================================*/
	if(NULL==_n1->m_left && NULL!=_n2->m_left)
	{
		return 0;
	}
	
	if(NULL!=_n1->m_left && NULL==_n2->m_left)
	{
		return 0;
	}
	/*===============================================================*/	
	if(NULL==_n1->m_right && NULL!=_n2->m_right)
	{
		return 0;
	}
	
	if(NULL!=_n1->m_right && NULL==_n2->m_right)
	{
		return 0;
	}
	/*===============================================================*/
		return (checkSimilarTree(_n1->m_left,_n2->m_left) && checkSimilarTree(_n2->m_right,_n2->m_right));
}
/*===============================================================*/
	
int isPerfectTree(Tree* _tree)
{
	int res;
	if(!_tree)
	{
		return 1;
	}
	res=checkPerfectTree(_tree->m_root);
}

static int checkPerfectTree(Node* _node)
{
	if(NULL==_node)
	{
		return 1;
	}
	
	if(NULL==_node->m_left&&NULL==_node->m_right)
	{
		return 1;
	}
	/*===============================================================*/
	if(NULL==_node->m_left && NULL!=_node->m_right
		||NULL!=_node->m_left && NULL==_node->m_right)
	{
		return 0;
	}
	/*===============================================================*/	
	if(NULL!=_node->m_left && NULL!=_node->m_right)
	{
		return (checkFullTree(_node->m_left) && checkFullTree(_node->m_right));
	}
}
/*===============================================================*/	

void MirrorTree(Tree* _tree)
{
	int res;
	if(!_tree)
	{
		return;
	}
	createMirrorTree(_tree->m_root);
}

static void createMirrorTree(Node* _node)
{
	Node* temp=NULL;
	if(NULL==_node)
	{
		return;
	}
	
	if(NULL==_node->m_left && NULL==_node->m_right)
	{
		return;
	}
	
	if(NULL!=_node->m_left && NULL!=_node->m_right)
	{
		printf("1 item = %d\n",_node->m_data);
		temp=_node->m_left;
		_node->m_left=_node->m_right;
		_node->m_right=temp;
	}
	
	else if(NULL!=_node->m_left && NULL==_node->m_right)
	{
		printf("2 item = %d\n",_node->m_data);
		_node->m_right=_node->m_left;
		_node->m_left=NULL;
	}
	
	else if(NULL==_node->m_left && NULL!=_node->m_right)
	{
		printf("3 item = %d\n",_node->m_data);
		_node->m_left=_node->m_right;
		_node->m_right=NULL;
	}
	
	createMirrorTree(_node->m_left);
	createMirrorTree(_node->m_right);
}

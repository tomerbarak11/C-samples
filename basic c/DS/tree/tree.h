/**************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: tree header
* 						DATE: 10-07-2019 11:16:03
*******************************************************************************/

#ifndef __TREE_H__
#define __TREE_H__
#include "ADTDefs.h"

typedef enum{
	PRE_ORDER,
	IN_ORDER,
	POST_ORDER,
}TreeTraverse;

typedef struct Node Node;
typedef struct Tree Tree;

/**@Description: creates the tree
 * @params _x :
 * @returns: returns a pointer to new tree or null if fails
 */
Tree* TreeCreate();

/**@Description: destroys the tree
 * @params _x : pointer to tree
 * @returns: returns null
 */
void TreeDestroy(Tree* _tree);

/**@Description: inserts a new data the tree
 * @params _x :pointer to the tree and data to insert
 * @returns: returns null
 */
ADTErr TreeInsert(Tree* _tree,int _data);

/**@Description: search for a specific data in tree
 * @params _x : pointer to the tree and data to find
 * @returns: returns 1 if data is found and 0 if not
 */
int TreeIsDataFound (Tree* _tree,int _data);

/**@Description: prints trees data
 * @params _x : pointer to tree and mode of printing, 1 for preorder,2 inorder,3 postorder
 * @returns: returns null
 */
void TreePrint(Tree* _tree,TreeTraverse _traverseMode);

/**@Description: creates new node in tree
 * @params _x : data to insert
 * @returns: returns new node
 */
Node* createNode(int _data);

/**@Description: destroys the sub tree
 * @params _x : node of sub tree to be destroyed
 * @returns:
 */
void destroyTreeSubtree(Node* _n);

/**@Description: print tree by modes
 * @params _x : pointer to root
 * @returns:
 */
void printPreorder(Node* _node);
void printInorder(Node* _node);
void printPostorder(Node* _node);
int isFullTree(Tree* _tree);
int isSimilarTree(Tree* _tree1,Tree* _tree2);
int isPerfectTree(Tree* _tree);
void MirrorTree(Tree* _tree);
#endif          /* tree s*/

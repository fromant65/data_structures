#include "btree.h"
#include "../queue/gqueue.h"
#include <stdlib.h>
/**
 * @brief Returns an empty tree
 */
BTree newBtree() {return NULL;}

/**
 * @brief Given a BTree, frees its nodes without freeing the data
 */
void BTreeFree(BTree t){
    if(t==NULL) return;
    BTreeFree(t->left);
    BTreeFree(t->right);
    free(t);
}

/**
 * @brief Given a BTree, returns true (1) if it's an empty tree, else returns 0
 */
int BTreeEmpty(BTree t){return t==NULL;}

/**
 * @brief Given a pointer and two BTrees, creates a new BTree with the data given and the BTrees
 * as its children, and returns it
 */
BTree BTreeJoin(void* data, BTree left, BTree right){
    BTree newT = malloc(sizeof(BTree_Node));
    newT->data=data;
    newT->left=left;
    newT->right=right;
    return newT;
}

/**
 * @brief Given a BTree, an order of traversing (PRE, IN or POST order) and a Parsing function, 
 * applies the parsing function to each node of the Tree in the given order 
 */
void BTreeDFS(BTree t, Order o, ParsingFunction f){
    if(o==BTREE_PRE) f(t->data);
    BTreeDFS(t->left,o,f);
    if(o==BTREE_IN) f(t->data);
    BTreeDFS(t->right,o,f);
    if(o==BTREE_POST) f(t->data);
}

/**
 * @brief Internal function to act as a freeing function which doesn't destroy the passed data
 */
void nonDestroy(void* data){return;}
/**
 * @brief Given a BTree and a Parsing Functions, applies said function to each node of the Tree
 * in BFS order
 */
void BTreeBFS(BTree t, ParsingFunction f){
    Queue q = newQueue(2048);
    BTree aux=t;
    q=enQueue(q,t);
    while(!QueueEmpty(q)){
        f(((BTree)QueueStart(q))->data);
        if(aux->left!=NULL) q=enQueue(q,aux->left);
        if(aux->right!=NULL) q=enQueue(q,aux->right);
        q=deQueue(q,nonDestroy);
        aux=QueueStart(q);
    }
    destroyQueue(q,nonDestroy);
}

/**
 * @brief Given a BTree and a Comparison Function, checks if the tree is a Binary Search Tree  
 * @return 1 if the BTree is a BST, 0 otherwise
 **/
int BTreeCheckBST(BTree t, CompareFunction f);

/**
 * @brief Given a BTree, returns its height (i.e. the longest route until it reaches a NULL child).
 * An empty BTree has height 0
 */
int BTreeHeight(BTree t);

/**
 * @brief Given a Binary Search Tree, inserts the given data in the position that preserves the
 * BST property. ONLY WORKS IF THE GIVEN TREE IS A BST
 */
BTree BSTreeInsert(BTree t, void* data, CompareFunction f);

/**
 * @brief Given a BTree, checks if its an AVL Tree
 * @return 1 if it's an ALV, 0 otherwise
 */
int BTreeCheckAVL(BTree t, CompareFunction f);

/**
 * @brief Given an AVL Tree, inserts the given data in the position that preserves the
 * AVL property. ONLY WORKS IF THE GIVEN TREE IS AN AVL
 */
BTree AVLTreeInsert(BTree t, void* data, CompareFunction f);
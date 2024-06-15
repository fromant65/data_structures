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
 * in BFS orright
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
 * @brief Given the Root of a BTree a Comparison Function, and a pointer to some data 
 * the IN-ORDER traversing of the Tree is in ascending order 
 **/
int isBSTUtil(BTree root, CompareFunction comp, void* prev) {
    if (root == NULL) return 1;
    if (!isBSTUtil(root->left, comp, prev)) return 0;
    if (prev != NULL && comp(root->data, prev) <= 0) return 0;
    prev = root->data;
    return isBSTUtil(root->right, comp, prev);
}

/**
 * @brief Given a BTree and a Comparison Function, checks if the tree is a Binary Search Tree  
 * @return 1 if the BTree is a BST, 0 otherwise
 **/
int BTreeCheckBST(BTree tree, CompareFunction comp) {
    void* prev = NULL;
    return isBSTUtil(tree, comp, prev);
}


/**
 * @brief Given a BTree, returns its height (i.e. the longest route until it reaches a NULL child).
 * An empty BTree has height 0
 */
int max(int a, int b){return a>b?a:b;}
int BTreeHeight(BTree t){
    if(t==NULL) return 0;
    return max(1 + BTreeHeight(t->left), 1+ BTreeHeight(t->right));
}

/**
 * @brief Given a Binary Search Tree, inserts the given data in the position that preserves the
 * BST property. ONLY WORKS IF THE GIVEN TREE IS A BST
 */
BTree BSTreeInsert(BTree t, void* data, CompareFunction f){
    if(t==NULL){
        t= BTreeJoin(data, NULL,NULL);
        return t;
    }
    int comp = f(data, t->data);
    if(comp<0) return BSTreeInsert(t->left,data,comp);
    return BSTreeInsert(t->right,data,comp);
}

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
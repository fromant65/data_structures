#ifndef __BTREE_H__
#define __BTREE_H__

typedef struct _BTNODE{
    void* data;
    struct _BTNODE* left;
    struct _BTNODE* right;
}BTree_Node;

typedef BTree_Node *BTree;

typedef enum{
    BTREE_PRE,
    BTREE_IN,
    BTREE_POST
}Order;

typedef void (*ParsingFunction)(void* data);
typedef int (*CompareFunction)(void* d1, void* d2);

/**
 * @brief Returns an empty tree
 */
BTree newBtree();

/**
 * @brief Given a BTree, frees its nodes without freeing the data
 */
void BTreeFree(BTree t);

/**
 * @brief Given a BTree, returns true (1) if it's an empty tree, else returns 0
 */
int BTreeEmpty(BTree t);

/**
 * @brief Given a pointer and two BTrees, creates a new BTree with the data given and the BTrees
 * as its children, and returns it
 */
BTree BTreeJoin(void* data, BTree left, BTree right);

/**
 * @brief Given a BTree, an order of traversing (PRE, IN or POST order) and a Parsing function, 
 * applies the parsing function to each node of the Tree in the given order 
 */
void BTreeDFS(BTree t, Order o, ParsingFunction f);

/**
 * @brief Given a BTree and a Parsing Functions, applies said function to each node of the Tree
 * in BFS order
 */
void BTreeBFS(BTree t, ParsingFunction f);

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


#endif
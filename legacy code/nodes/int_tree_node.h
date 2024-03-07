#ifndef INT_TREE_NODE_H
#define INT_TREE_NODE_H

typedef struct IntTreeNode_
{
    int value;
    struct IntTreeNode_ *leftChild;
    struct IntTreeNode_ *rightChild;
} IntTreeNode;

IntTreeNode *newNode(int value);

#endif
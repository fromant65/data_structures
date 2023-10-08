#ifndef INT_TREE_NODE_H
#define INT_TREE_NODE_H

typedef struct
{
    int value;
    struct IntTreeNode *leftChild;
    struct IntTreeNode *rightChild;
} IntTreeNode;

IntTreeNode *newNode(int value);

#endif
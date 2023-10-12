#ifndef INT_TREE_NODE_H
#define INT_TREE_NODE_H

typedef struct IntTreeNode IntTreeNode;

struct IntTreeNode
{
    int value;
    IntTreeNode *leftChild;
    IntTreeNode *rightChild;
};

IntTreeNode *newNode(int value);

#endif
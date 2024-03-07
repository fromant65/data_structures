#include <stdlib.h>
#include "int_tree_node.h"

IntTreeNode *newNode(int value)
{
    IntTreeNode *n = malloc(sizeof(IntTreeNode));
    n->value = value;
    n->leftChild = NULL;
    n->rightChild = NULL;
    return n;
}
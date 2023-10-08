#ifndef TREE_H
#define TREE_H

typedef struct
{
    struct IntTreeNode *head;
} BinarySearchTree;

BinarySearchTree *newTree();
BinarySearchTree *listToTree(int values[], int size);
void addElement(BinarySearchTree *tree, int value);
int searchElement(BinarySearchTree *tree, int value);
void deleteElement(BinarySearchTree *tree, int value);
IntTreeNode *deleteNode(IntTreeNode *root, int value);
IntTreeNode *minValueNode(IntTreeNode *node);
IntTreeNode *maxValueNode(IntTreeNode *node);
void pre_order_print(IntTreeNode *head);
void in_order_print(IntTreeNode *head);
void post_order_print(IntTreeNode *head);
#endif

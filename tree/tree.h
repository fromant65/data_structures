#ifndef TREE_H
#define TREE_H

typedef struct
{
    IntTreeNode *head;
    int size;
} BinarySearchTree;

BinarySearchTree *newTree();
BinarySearchTree *listToTree(int values[], int size);
void addElement(BinarySearchTree *tree, int value);
int searchElement(BinarySearchTree *tree, int value);
void deleteElement(BinarySearchTree *tree, int value);
void freeTree(BinarySearchTree *tree);
IntTreeNode *minValueNode(IntTreeNode *node);
IntTreeNode *maxValueNode(IntTreeNode *node);
char *stringify_tree(BinarySearchTree *t, char method[]);
#endif

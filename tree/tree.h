#ifndef TREE_H
#define TREE_H

#include "../nodes/int_tree_node.h"

typedef struct
{
    IntTreeNode *head;
    int size;
} BinarySearchTree;

BinarySearchTree *newTree();
BinarySearchTree *listToTree(int values[], int size);     // Creates a new binary search tree from an array
void addElement(BinarySearchTree *tree, int value);       // Adds an element to the BST
int searchElement(BinarySearchTree *tree, int value);     // Looks for an element and returns 1 if it's in the tree or 0 otherwise
void deleteElement(BinarySearchTree *tree, int value);    // Deletes an element from the tree
void freeTree(BinarySearchTree *tree);                    // Deletes the tree and frees memory
IntTreeNode *minValueNode(IntTreeNode *node);             // Returns the smallest value node
IntTreeNode *maxValueNode(IntTreeNode *node);             // Returns the highest value node
int *tree_to_array(BinarySearchTree *t, char method[]);   // Returns an array of the tree values in pre, in or post order
char *stringify_tree(BinarySearchTree *t, char method[]); // Returns a string of the tree values in pre, in or post order
#endif

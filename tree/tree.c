#include <stdlib.h>
#include <stdio.h>
#include "../nodes/int_tree_node.h"
#include "tree.h"

BinarySearchTree *newTree()
{
    BinarySearchTree *new_tree = malloc(sizeof(BinarySearchTree));
    new_tree->head = NULL;
    return new_tree;
}

BinarySearchTree *listToTree(int values[], int size)
{
    BinarySearchTree *new_tree = newTree();
    for (int i = 0; i < size; i++)
    {
        addElement(new_tree, values[i]);
    }
    return new_tree;
}

void addElement(BinarySearchTree *tree, int value)
{
    IntTreeNode *new_node = newNode(value);
    if (tree->head == NULL)
    {
        tree->head = new_node;
        return;
    }
    IntTreeNode *aux = tree->head;
    IntTreeNode *prev = tree->head;
    while (aux != NULL)
    {
        if (value < aux->value)
        {
            prev = aux;
            aux = prev->leftChild;
        }
        else if (value > aux->value)
        {
            prev = aux;
            aux = prev->rightChild;
        }
        else
        {
            aux = NULL;
        }
    }
    if (value == prev->value)
    {
        return;
    }
    if (value < prev->value)
    {
        prev->leftChild = new_node;
    }
    else
    {
        prev->rightChild = new_node;
    }
}

int searchElement(BinarySearchTree *tree, int value)
{
    IntTreeNode *new_node = newNode(value);
    IntTreeNode *aux = tree->head;
    while (aux != NULL && aux->value != value)
    {
        if (value > aux->value)
        {
            aux = aux->rightChild;
        }
        else
        {
            aux = aux->leftChild;
        }
    }
    if (aux == NULL)
    {
        return 0; // element not found
    }
    else
    {
        return 1; // element found
    }
}

void deleteElement(BinarySearchTree *tree, int value)
{
    if (tree->head == NULL)
    {
        printf("The tree is empty\n");
        return;
    }
    IntTreeNode *head = deleteNode(tree->head, value);
    tree->head = head;
}

IntTreeNode *deleteNode(IntTreeNode *root, int value)
{
    if (root == NULL)
    {
        return root;
    }

    if (value < root->value)
    {
        root->leftChild = deleteNode(root->leftChild, value);
    }
    else if (value > root->value)
    {
        root->rightChild = deleteNode(root->rightChild, value);
    }
    else
    {
        if (root->leftChild == NULL)
        {
            IntTreeNode *temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL)
        {
            IntTreeNode *temp = root->leftChild;
            free(root);
            return temp;
        }

        IntTreeNode *temp = minValueNode(root->rightChild);

        root->value = temp->value;

        root->rightChild = deleteNode(root->rightChild, temp->value);
    }

    return root;
}

IntTreeNode *minValueNode(IntTreeNode *node)
{
    IntTreeNode *current = node;

    while (current && current->leftChild != NULL)
    {
        current = current->leftChild;
    }

    return current;
}

IntTreeNode *maxValueNode(IntTreeNode *node)
{
    IntTreeNode *current = node;

    while (current && current->rightChild != NULL)
    {
        current = current->rightChild;
    }

    return current;
}

void pre_order_print(IntTreeNode *head)
{
    if (head == NULL)
    {
        return;
    }
    printf("%d, ", head->value);
    pre_order_print(head->leftChild);
    pre_order_print(head->rightChild);
}
void in_order_print(IntTreeNode *head)
{
    if (head == NULL)
    {
        return;
    }
    in_order_print(head->leftChild);
    printf("%d, ", head->value);
    in_order_print(head->rightChild);
}
void post_order_print(IntTreeNode *head)
{
    if (head == NULL)
    {
        return;
    }
    post_order_print(head->leftChild);
    post_order_print(head->rightChild);
    printf("%d, ", head->value);
}
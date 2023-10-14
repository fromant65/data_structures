#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../nodes/int_tree_node.h"
#include "tree.h"

BinarySearchTree *newTree()
{
    BinarySearchTree *new_tree = malloc(sizeof(BinarySearchTree));
    new_tree->head = NULL;
    new_tree->size = 0;
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
        tree->size += 1;
        return;
    }
    IntTreeNode *aux = tree->head;
    IntTreeNode *prev = tree->head;
    while (aux != NULL)
    {
        prev = aux;
        if (value < aux->value)
        {
            aux = prev->leftChild;
        }
        else if (value > aux->value)
        {
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
    tree->size = tree->size + 1;
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

void deleteElement(BinarySearchTree *tree, int value)
{
    if (tree->head == NULL)
    {
        printf("The tree is empty\n");
        return;
    }
    if (searchElement(tree, value))
    {
        IntTreeNode *head = deleteNode(tree->head, value);
        tree->head = head;
        tree->size = tree->size - 1;
    }
}

void freeNodes(IntTreeNode *head)
{
    if (head == NULL)
    {
        return;
    }
    IntTreeNode *left = head->leftChild;
    IntTreeNode *rigth = head->rightChild;
    free(head);
    freeNodes(left);
    freeNodes(rigth);
}

void freeTree(BinarySearchTree *tree)
{
    IntTreeNode *head = tree->head;
    freeNodes(head);
    free(tree);
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

void preOrder(IntTreeNode *node, int **arr, int *size, int *index)
{
    if (node == NULL)
        return;

    if (*index >= *size)
    {
        *size *= 2;
        *arr = realloc(*arr, *size * sizeof(int));
        if (*arr == NULL)
        {
            printf("Memory allocation failed in inOrder\n");
            exit(1);
        }
    }

    (*arr)[(*index)++] = node->value;

    preOrder(node->leftChild, arr, size, index);
    preOrder(node->rightChild, arr, size, index);
}

void inOrder(IntTreeNode *node, int **arr, int *size, int *index)
{
    if (node == NULL)
        return;

    inOrder(node->leftChild, arr, size, index);

    if (*index >= *size)
    {
        *size *= 2;
        *arr = realloc(*arr, *size * sizeof(int));
        if (*arr == NULL)
        {
            printf("Memory allocation failed in inOrder\n");
            exit(1);
        }
    }

    (*arr)[(*index)++] = node->value;

    inOrder(node->rightChild, arr, size, index);
}

void postOrder(IntTreeNode *node, int **arr, int *size, int *index)
{
    if (node == NULL)
        return;

    postOrder(node->leftChild, arr, size, index);
    postOrder(node->rightChild, arr, size, index);

    if (*index >= *size)
    {
        *size *= 2;
        *arr = realloc(*arr, *size * sizeof(int));
        if (*arr == NULL)
        {
            printf("Memory allocation failed in inOrder\n");
            exit(1);
        }
    }

    (*arr)[(*index)++] = node->value;
}

int *tree_to_array(BinarySearchTree *t, char method[])
{
    int size = t->size;
    int *arr = malloc(sizeof(int) * size);

    int index = 0;
    if (!strcmp(method, "pre"))
    {
        preOrder(t->head, &arr, &size, &index);
    }
    else if (!strcmp(method, "in"))
    {
        inOrder(t->head, &arr, &size, &index);
    }
    else if (!strcmp(method, "post"))
    {
        postOrder(t->head, &arr, &size, &index);
    }
    else
    {
        printf("Chosen method is not valid. Choose 'in', 'pre' or 'post'");
    }
    return arr;
}

char *stringify_tree(BinarySearchTree *t, char method[])
{
    int size = t->size;
    char *str = malloc(sizeof(char) * size * 12);
    if (str == NULL)
    {
        printf("Memory allocation failed in stringify_tree\n");
        exit(1);
    }
    str[0] = '\0';
    int *arr;
    if (!strcmp(method, "pre"))
    {
        arr = tree_to_array(t, "pre");
    }
    else if (!strcmp(method, "in"))
    {
        arr = tree_to_array(t, "in");
    }
    else if (!strcmp(method, "post"))
    {
        arr = tree_to_array(t, "post");
    }
    else
    {
        free(str);
        return "Chosen method is not valid. Choose 'in', 'pre' or 'post'";
    }
    for (int i = 0; i < size; i++)
    {
        sprintf(str + strlen(str), "%d ", arr[i]);
    }
    sprintf(str + strlen(str) - 1, "\n");
    return str;
}

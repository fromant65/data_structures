#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_test.h"
#include "../nodes/int_tree_node.h"
#include "../tree/tree.h"

int test_new_tree();
int test_list_to_tree();
int test_add_element();
int test_search_element();
int check_BST_property(IntTreeNode *head);
int test_delete_element();
int test_max_value_node();
int test_min_value_node();
int test_stringify_tree();

void test_tree()
{
    printf("Testing new_tree function...\n");
    int t_new_tree = test_new_tree();
    printf("Testing list_to_tree function...\n");
    int t_list_to_tree = test_list_to_tree();
    printf("Testing add_element function...\n");
    int t_add_element = test_add_element();
    printf("Testing search_element function...\n");
    int t_search_element = test_search_element();
    printf("Testing delete_element function...\n");
    int t_delete_element = test_delete_element();
    printf("Testing max_value_node function...\n");
    int t_max_value_node = test_max_value_node();
    printf("Testing min_value_node function...\n");
    int t_min_value_node = test_min_value_node();
    printf("Testing stringify_tree function...\n");
    int t_stringify_tree = test_stringify_tree();

    int test_result = t_new_tree && t_list_to_tree && t_add_element && t_search_element && t_delete_element && t_max_value_node && t_min_value_node && t_stringify_tree;

    if (test_result)
    {
        printf("Tests for tree have passed successfully\n");
    }
    else
    {
        printf("Tests have failed:\n");
        if (!t_new_tree)
        {
            printf("new_tree function not working properly\n");
        }
        if (!t_list_to_tree)
        {
            printf("list_to_tree function not working properly\n");
        }
        if (!t_add_element)
        {
            printf("add_element function not working properly\n");
        }
        if (!t_search_element)
        {
            printf("search_element function not working properly\n");
        }
        if (!t_delete_element)
        {
            printf("delete_element function not working properly\n");
        }
        if (!t_max_value_node)
        {
            printf("max_value_node function not working properly\n");
        }
        if (!t_min_value_node)
        {
            printf("min_value_node function not working properly\n");
        }
        if (!t_stringify_tree)
        {
            printf("stringify_tree function not working properly\n");
        }
    }
}

int test_new_tree()
{
    BinarySearchTree *tree = newTree();
    IntTreeNode *head = tree->head;
    int size = tree->size;
    int predicate = head == NULL && size == 0;
    freeTree(tree);
    return predicate;
}

int test_list_to_tree()
{
    int list[] = {10, 5, 2, 3, 8, 15, 17, 11, 14, 13, 11};
    BinarySearchTree *tree = listToTree(list, 11);
    int predicate = 1;
    IntTreeNode *aux = tree->head;
    predicate &= aux->value == 10;
    aux = aux->rightChild;
    predicate &= aux->value == 15;
    aux = aux->leftChild;
    predicate &= aux->value == 13;
    printf("%s", stringify_tree(tree, "in"));
    freeTree(tree);
    return predicate;
}

int test_add_element()
{
    BinarySearchTree *tree = newTree();
    addElement(tree, 10);
    IntTreeNode *head = tree->head;
    int size = tree->size;
    int predicate = head->value == 10 && size == 1;
    freeTree(tree);
    return predicate;
}

int test_search_element()
{
    int list[] = {10, 15, 5, 8, 2, 1, 13, 14, 11, 12};
    BinarySearchTree *tree = listToTree(list, 10);
    int search1 = searchElement(tree, 13);
    int search2 = searchElement(tree, 7);
    int search3 = searchElement(tree, 10);
    freeTree(tree);
    return search1 == 1 && search2 == 0 && search3 == 1;
}

int check_BST_property(IntTreeNode *head)
{
    if (head == NULL)
    {
        return 1;
    }
    IntTreeNode *left = head->leftChild;
    IntTreeNode *right = head->rightChild;
    int predicate1 = 1, predicate2 = 1;
    if (left != NULL && right != NULL)
    {
        predicate1 = left->value < head->value;
        predicate2 = right->value > head->value;
    }
    if (predicate1 && predicate2)
    {
        int c1 = 1, c2 = 1;
        if (left != NULL)
            c1 = check_BST_property(left);
        if (right != NULL)
            c2 = check_BST_property(right);
        return c1 && c2;
    }
    else
    {
        return 0;
    }
}

int test_delete_element()
{
    int list[] = {10, 15, 5, 8, 2, 1, 13, 14, 11, 12};
    BinarySearchTree *tree = listToTree(list, 10);
    deleteElement(tree, 10);
    IntTreeNode *head = tree->head;
    int predicate = head->value != 10;
    int bst_property = check_BST_property(tree->head);
    freeTree(tree);
    return predicate && bst_property;
}

int test_max_value_node()
{
    int list[] = {10, 15, 5, 8, 2, 1, 13, 14, 11, 12};
    BinarySearchTree *tree = listToTree(list, 10);
    IntTreeNode *max = maxValueNode(tree->head);
    int predicate = max->value == 15;
    freeTree(tree);
    return predicate;
}

int test_min_value_node()
{
    int list[] = {10, 15, 5, 8, 2, 1, 13, 14, 11, 12};
    BinarySearchTree *tree = listToTree(list, 10);
    IntTreeNode *min = minValueNode(tree->head);
    int predicate = min->value == 1;
    freeTree(tree);
    return predicate;
}

int test_stringify_tree()
{
    int list[] = {10, 15, 5, 8, 2, 1, 13, 14, 11, 12};
    BinarySearchTree *tree = listToTree(list, 10);
    char *in_order = stringify_tree(tree, "in");
    char *pre_order = stringify_tree(tree, "pre");
    char *post_order = stringify_tree(tree, "post");
    freeTree(tree);
    printf("in order: %s", in_order);
    printf("pre order: %s", pre_order);
    printf("post order: %s", post_order);
    int predicate =
        !strcmp(in_order, "1 2 5 8 10 11 12 13 14 15 \n") &&
        !strcmp(pre_order, "10 5 2 1 8 15 13 11 12 14 \n") &&
        !strcmp(post_order, "1 2 8 5 12 11 14 13 15 10 \n");
    return predicate;
}

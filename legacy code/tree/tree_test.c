#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_test.h"
#include "../nodes/int_tree_node.h"
#include "tree.h"

void test_new_tree();
void test_list_to_tree();
void test_add_element();
void test_search_element();
int check_BST_property(IntTreeNode *head);
void test_delete_element();
void test_max_value_node();
void test_min_value_node();
void test_tree_to_array();
void test_stringify_tree();

void test_tree()
{
    printf("Testing new_tree function...\n");
    test_new_tree();
    printf("Testing list_to_tree function...\n");
    test_list_to_tree();
    printf("Testing add_element function...\n");
    test_add_element();
    printf("Testing search_element function...\n");
    test_search_element();
    printf("Testing delete_element function...\n");
    test_delete_element();
    printf("Testing max_value_node function...\n");
    test_max_value_node();
    printf("Testing min_value_node function...\n");
    test_min_value_node();
    printf("Testing tree_to_array function...\n");
    test_tree_to_array();
    printf("Testing stringify_tree function...\n");
    test_stringify_tree();
}

void test_new_tree()
{
    BinarySearchTree *tree = newTree();
    IntTreeNode *head = tree->head;
    int size = tree->size;
    assert(head == NULL && size == 0);
    freeTree(tree);
}

void test_list_to_tree()
{
    int list[] = {10, 5, 2, 3, 8, 15, 17, 11, 14, 13, 11};
    BinarySearchTree *tree = listToTree(list, 11);
    IntTreeNode *aux = tree->head;
    assert(aux->value == 10);
    aux = aux->rightChild;
    assert(aux->value == 15);
    aux = aux->leftChild;
    assert(aux->value == 11);
    printf("%s", stringify_tree(tree, "in"));
    freeTree(tree);
}

void test_add_element()
{
    BinarySearchTree *tree = newTree();
    addElement(tree, 10);
    IntTreeNode *head = tree->head;
    int size = tree->size;
    assert(head->value == 10 && size == 1);
    freeTree(tree);
}

void test_search_element()
{
    int list[] = {10, 15, 5, 8, 2, 1, 13, 14, 11, 12};
    BinarySearchTree *tree = listToTree(list, 10);
    int search1 = searchElement(tree, 13);
    int search2 = searchElement(tree, 7);
    int search3 = searchElement(tree, 10);
    assert(search1 == 1 && search2 == 0 && search3 == 1);
    freeTree(tree);
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

void test_delete_element()
{
    int list[] = {10, 15, 5, 8, 2, 1, 13, 14, 11, 12};
    BinarySearchTree *tree = listToTree(list, 10);
    deleteElement(tree, 10);
    IntTreeNode *head = tree->head;
    assert(head->value != 10);
    int bst_property = check_BST_property(tree->head);
    assert(bst_property);
    freeTree(tree);
}

void test_max_value_node()
{
    int list[] = {10, 15, 5, 8, 2, 1, 13, 14, 11, 12};
    BinarySearchTree *tree = listToTree(list, 10);
    IntTreeNode *max = maxValueNode(tree->head);
    assert(max->value == 15);
    freeTree(tree);
}

void test_min_value_node()
{
    int list[] = {10, 15, 5, 8, 2, 1, 13, 14, 11, 12};
    BinarySearchTree *tree = listToTree(list, 10);
    IntTreeNode *min = minValueNode(tree->head);
    assert(min->value == 1);
    freeTree(tree);
}

void test_tree_to_array()
{
    int list[] = {10, 15, 5, 8, 2, 1, 13, 14, 11, 12};
    BinarySearchTree *tree = listToTree(list, 10);
    int *in_order = tree_to_array(tree, "in");
    int *pre_order = tree_to_array(tree, "pre");
    int *post_order = tree_to_array(tree, "post");
    freeTree(tree);

    assert(
        pre_order[0] == 10 && pre_order[1] == 5 && pre_order[2] == 2 && pre_order[3] == 1 && pre_order[4] == 8 &&
        pre_order[5] == 15 && pre_order[6] == 13 && pre_order[7] == 11 && pre_order[8] == 12 && pre_order[9] == 14);
    assert(
        in_order[0] == 1 && in_order[1] == 2 && in_order[2] == 5 && in_order[3] == 8 && in_order[4] == 10 &&
        in_order[5] == 11 && in_order[6] == 12 && in_order[7] == 13 && in_order[8] == 14 && in_order[9] == 15);
    assert(
        post_order[0] == 1 && post_order[1] == 2 && post_order[2] == 8 && post_order[3] == 5 && post_order[4] == 12 &&
        post_order[5] == 11 && post_order[6] == 14 && post_order[7] == 13 && post_order[8] == 15 && post_order[9] == 10);
    free(in_order);
    free(pre_order);
    free(post_order);
}

void test_stringify_tree()
{
    int list[] = {10, 15, 5, 8, 2, 1, 13, 14, 11, 12};
    BinarySearchTree *tree = listToTree(list, 10);
    char *in_order = stringify_tree(tree, "in");
    char *pre_order = stringify_tree(tree, "pre");
    char *post_order = stringify_tree(tree, "post");
    freeTree(tree);
    printf("pre order: %s", pre_order);
    printf("in order: %s", in_order);
    printf("post order: %s", post_order);
    assert(strcmp(in_order, "1 2 5 8 10 11 12 13 14 15\n") == 0);
    assert(strcmp(pre_order, "10 5 2 1 8 15 13 11 12 14\n") == 0);
    assert(strcmp(post_order, "1 2 8 5 12 11 14 13 15 10\n") == 0);
    free(in_order);
    free(pre_order);
    free(post_order);
}

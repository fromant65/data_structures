#include <stdio.h>
#include <stdlib.h>
#include "tree_test.h"
#include "../nodes/int_tree_node.h"
#include "../tree/tree.h"

void format_recursive_tree_print(void (*func)(struct IntTreeNode *), struct IntTreeNode *head)
{
    func(head);
    printf("\n");
}

void test_tree()
{
    printf("Creating empty tree\n");
    BinarySearchTree *tree = newTree();
    int list[] = {10, 15, 5, 8, 2, 1, 13, 14, 11, 12};
    printf("Creating list tree\n");
    BinarySearchTree *list_tree = listToTree(list, 10);
    printf("Adding elements to empty tree\n");
    addElement(tree, 10);
    addElement(tree, 4);
    addElement(tree, 7);
    printf("in order list tree\n");
    format_recursive_tree_print(in_order_print, list_tree->head);
    printf("in order tree\n");
    format_recursive_tree_print(in_order_print, tree->head);
    printf("pre order list tree\n");
    format_recursive_tree_print(pre_order_print, list_tree->head);
    printf("post order list tree\n");
    format_recursive_tree_print(post_order_print, list_tree->head);
    printf("deleting element list tree\n");
    deleteElement(list_tree, 13);
    printf("in order list tree\n");
    format_recursive_tree_print(in_order_print, list_tree->head);
}

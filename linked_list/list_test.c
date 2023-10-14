#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "int_list.h"
#include "../nodes/int_node.h"

int test_new_list();
int test_push_item();
int test_add_item();
int test_delete_item();
int test_list_to_array();
int test_stringify_list();

void test_linked_list()
{
    printf("Testing newList function...\n");
    int t_new_list = test_new_list();
    printf("Testing push_item function...\n");
    int t_push_item = test_push_item();
    printf("Testing add_item function...\n");
    int t_add_item = test_add_item();
    printf("Testing delete_item function...\n");
    int t_delete_item = test_delete_item();
    printf("Testing list_to_array function...\n");
    int t_list_to_array = test_list_to_array();
    printf("Testing stringify_list function...\n");
    int t_stringify_list = test_stringify_list();
    int test_result = t_new_list && t_push_item && t_add_item && t_delete_item && t_list_to_array && t_stringify_list;
    if (test_result)
    {
        printf("Tests for linked list have passed successfully\n");
    }
    else
    {
        if (!t_new_list)
        {
            printf("new_list function not wotking properly\n");
        }
        if (!t_push_item)
        {
            printf("push_item function not wotking properly\n");
        }
        if (!t_add_item)
        {
            printf("add_item function not wotking properly\n");
        }
        if (!t_delete_item)
        {
            printf("delete_item function not wotking properly\n");
        }
        if (!t_list_to_array)
        {
            printf("list_to_array function not wotking properly\n");
        }
        if (!t_stringify_list)
        {
            printf("stringify_list function not wotking properly\n");
        }
    }
}

int test_new_list()
{
    IntLinkedList *list = newList();
    int predicate = (list->first == NULL && list->size == 0);
    free_list(list);
    return predicate;
}

int test_push_item()
{
    IntLinkedList *list = newList();
    int predicate = 1;
    push_item(list, 1);
    push_item(list, 2);
    IntNode *aux = list->first;
    predicate &= (aux->value == 1);
    aux = aux->next;
    predicate &= (aux->value == 2);
    aux = aux->next;
    predicate &= (aux == NULL);
    free_list(list);
    return predicate;
}

int test_add_item()
{
    IntLinkedList *l = newList();
    int predicate = 1;
    push_item(l, 1);
    push_item(l, 2);
    push_item(l, 3);
    push_item(l, 4);
    add_item(l, 5, 2);
    IntNode *aux = l->first;
    predicate &= (aux->value == 1);
    aux = aux->next;
    predicate &= (aux->value == 2);
    aux = aux->next;
    predicate &= (aux->value == 5);
    add_item(l, 6, 0);
    aux = l->first;
    predicate &= (aux->value == 6);
    free_list(l);
    return predicate;
}

int test_delete_item()
{
    IntLinkedList *l = newList();
    int predicate = 1;
    push_item(l, 1);
    push_item(l, 2);
    delete_item(l, 2);
    IntNode *aux = l->first;
    aux = aux->next;
    predicate &= (aux == NULL);
    delete_item(l, 1);
    aux = l->first;
    predicate &= (aux == NULL);
    free_list(l);
    return predicate;
}

int test_list_to_array()
{
    IntLinkedList *l = newList();
    int predicate;
    push_item(l, 1);
    push_item(l, 2);
    push_item(l, 3);
    int *arr = list_to_array(l);
    predicate = arr[0] == 1 && arr[1] == 2 && arr[2] == 3;
    return predicate;
}

int test_stringify_list()
{
    IntLinkedList *l = newList();
    push_item(l, 1);
    push_item(l, 2);
    push_item(l, 3);
    char *string = stringify_list(l);
    printf("List example: ");
    print_list(l);
    free_list(l);
    return !strcmp(string, "1 2 3\n");
}
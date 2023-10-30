#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "int_list.h"
#include "int_list_test.h"
#include "../../nodes/int_node.h"

void test_new_list();
void test_list_push_item();
void test_list_add_item();
void test_list_insert_item();
void test_list_delete_item();
void test_list_to_array();
void test_stringify_list();

void test_linked_list()
{
    printf("Testing newList function...\n");
    test_new_list();
    printf("Testing list_push_item function...\n");
    test_list_push_item();
    printf("Testing list_add_item function...\n");
    test_list_add_item();
    printf("Testing list_insert_item function...\n");
    test_list_insert_item();
    printf("Testing list_delete_item function...\n");
    test_list_delete_item();
    printf("Testing list_to_array function...\n");
    test_list_to_array();
    printf("Testing stringify_list function...\n");
    test_stringify_list();
}

void test_new_list()
{
    IntLinkedList *list = newList();
    assert(list->first == NULL && list->size == 0);
    free_list(list);
}

void test_list_push_item()
{
    IntLinkedList *list = newList();
    list_push_item(list, 1);
    list_push_item(list, 2);
    IntNode *aux = list->first;
    assert(aux->value == 1);
    aux = aux->next;
    assert(aux->value == 2);
    aux = aux->next;
    assert(aux == NULL);
    free_list(list);
}

void test_list_add_item()
{
    IntLinkedList *l = newList();
    list_push_item(l, 1);
    list_push_item(l, 2);
    list_push_item(l, 3);
    list_push_item(l, 4);
    list_add_item(l, 5, 2);
    IntNode *aux = l->first;
    assert(aux->value == 1);
    aux = aux->next;
    assert(aux->value == 2);
    aux = aux->next;
    assert(aux->value == 5);
    list_add_item(l, 6, 0);
    aux = l->first;
    assert(aux->value == 6);
    free_list(l);
}

void test_list_insert_item()
{
    IntLinkedList *l = newList();
    list_insert_item(l, 1);
    list_insert_item(l, 2);
    list_insert_item(l, 3);
    list_insert_item(l, 4);
    list_insert_item(l, 5);
    IntNode *aux = l->first;
    assert(aux->value == 5);
    aux = aux->next;
    assert(aux->value == 4);
    aux = aux->next;
    assert(aux->value == 3);
    free_list(l);
}

void test_list_delete_item()
{
    IntLinkedList *l = newList();
    list_push_item(l, 1);
    list_push_item(l, 2);
    list_delete_item(l, 2);
    IntNode *aux = l->first;
    aux = aux->next;
    assert(aux == NULL);
    list_delete_item(l, 1);
    aux = l->first;
    assert(aux == NULL);
    free_list(l);
}

void test_list_to_array()
{
    IntLinkedList *l = newList();
    list_push_item(l, 1);
    list_push_item(l, 2);
    list_push_item(l, 3);
    int *arr = list_to_array(l);
    assert(arr[0] == 1 && arr[1] == 2 && arr[2] == 3);
}

void test_stringify_list()
{
    IntLinkedList *l = newList();
    list_push_item(l, 1);
    list_push_item(l, 2);
    list_push_item(l, 3);
    char *string = stringify_list(l);
    printf("List example: ");
    print_list(l);
    free_list(l);
    assert(strcmp(string, "1 2 3\n") == 0);
}

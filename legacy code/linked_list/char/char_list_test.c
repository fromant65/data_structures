#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "char_list.h"
#include "char_list_test.h"
#include "../../nodes/char_node.h"

void test_char_new_list();
void test_char_list_push_item();
void test_char_list_add_item();
void test_char_list_delete_item();
void test_char_list_search_item();

void test_char_linked_list()
{
    printf("Testing newCharList function...\n");
    test_char_new_list();
    printf("Testing list_push_item function...\n");
    test_char_list_push_item();
    printf("Testing list_add_item function...\n");
    test_char_list_add_item();
    printf("Testing list_delete_item function...\n");
    test_char_list_delete_item();
    printf("Testing list_search_item function...\n");
    test_char_list_search_item();
}

void test_char_new_list()
{
    CharLinkedList *list = newCharList();
    assert(list->first == NULL && list->size == 0);
    char_free_list(list);
}

void test_char_list_push_item()
{
    CharLinkedList *list = newCharList();
    char_list_push_item(list, "Hola");
    char_list_push_item(list, " como andas");
    CharNode *aux = list->first;
    assert(strcmp(aux->value, "Hola") == 0);
    aux = aux->next;
    assert(strcmp(aux->value, " como andas") == 0);
    aux = aux->next;
    assert(aux == NULL);
    char_free_list(list);
}

void test_char_list_add_item()
{
    CharLinkedList *l = newCharList();
    char_list_push_item(l, "Hola");
    char_list_push_item(l, " como andas");
    char_list_push_item(l, " fulvio");
    char_list_push_item(l, " oo");
    char_list_add_item(l, " rey", 2);
    CharNode *aux = l->first;
    assert(strcmp(aux->value, "Hola") == 0);
    aux = aux->next;
    assert(strcmp(aux->value, " como andas") == 0);
    aux = aux->next;
    assert(strcmp(aux->value, " rey") == 0);
    char_list_add_item(l, "ivvvo ", 0);
    aux = l->first;
    assert(strcmp(aux->value, "ivvvo ") == 0);
    char_free_list(l);
}

void test_char_list_delete_item()
{
    CharLinkedList *l = newCharList();
    char_list_push_item(l, "Hola");
    char_list_push_item(l, " como");
    char_list_delete_item(l, " como");
    CharNode *aux = l->first;
    aux = aux->next;
    assert(aux == NULL);
    char_list_delete_item(l, "Hola");
    aux = l->first;
    assert(aux == NULL);
    char_free_list(l);
}

void test_char_list_search_item()
{
    CharLinkedList *l = newCharList();
    char_list_push_item(l, "Hola");
    char_list_push_item(l, " como");
    char_list_push_item(l, "estas");
    assert(char_list_search_item(l, "Hola"));
    assert(char_list_search_item(l, " como"));
    assert(char_list_search_item(l, "estas"));
    assert(!char_list_search_item(l, "pina"));
}

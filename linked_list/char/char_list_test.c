#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "char_list.h"
#include "../../nodes/char_node.h"

int test_char_new_list();
int test_char_list_push_item();
int test_char_list_add_item();
int test_char_list_delete_item();
int test_char_list_search_item();
int test_char_list_to_array();

void test_char_linked_list()
{
    printf("Testing newCharList function...\n");
    int t_new_list = test_char_new_list();
    printf("Testing list_push_item function...\n");
    int t_list_push_item = test_char_list_push_item();
    printf("Testing list_add_item function...\n");
    int t_list_add_item = test_char_list_add_item();
    printf("Testing list_delete_item function...\n");
    int t_list_delete_item = test_char_list_delete_item();
    printf("Testing list_search_item function...\n");
    int t_list_search_item = test_char_list_search_item();

    int test_char_result = t_new_list && t_list_push_item && t_list_add_item && t_list_search_item && t_list_delete_item ;

    if (test_char_result)
    {
        printf("Tests for linked list have passed successfully\n");
    }
    else
    {
        if (!t_new_list)
        {
            printf("new_list function not wotking properly\n");
        }
        if (!t_list_push_item)
        {
            printf("list_push_item function not wotking properly\n");
        }
        if (!t_list_add_item)
        {
            printf("list_add_item function not wotking properly\n");
        }
        if (!t_list_delete_item)
        {
            printf("list_delete_item function not wotking properly\n");
        }
        if (!t_list_search_item)
        {
            printf("list_search_item function not wotking properly\n");
        }
    }
}

int test_char_new_list()
{
    CharLinkedList *list = newCharList();
    int predicate = (list->first == NULL && list->size == 0);
    char_free_list(list);
    return predicate;
}

int test_char_list_push_item()
{
    CharLinkedList *list = newCharList();
    int predicate = 1;
    char_list_push_item(list, "Hola");
    char_list_push_item(list, " como andas");
    CharNode *aux = list->first;
    predicate &= !strcmp(aux->value,"Hola");
    aux = aux->next;
    predicate &= !strcmp(aux->value," como andas");
    aux = aux->next;
    predicate &= (aux == NULL);
    char_free_list(list);
    return predicate;
}

int test_char_list_add_item()
{
    CharLinkedList *l = newCharList();
    int predicate = 1;
    char_list_push_item(l, "Hola");
    char_list_push_item(l, " como andas");
    char_list_push_item(l, " fulvio");
    char_list_push_item(l, " oo");
    char_list_add_item(l, " rey", 2);
    CharNode *aux = l->first;
    predicate &= !strcmp(aux->value,"Hola");
    aux = aux->next;
    predicate &= !strcmp(aux->value," como andas");
    aux = aux->next;
    predicate &= !strcmp(aux->value," rey");
    char_list_add_item(l, "ivvvo ", 0);
    aux = l->first;
    predicate &= !strcmp(aux->value,"ivvvo ");
    char_free_list(l);
    return predicate;
}

int test_char_list_delete_item()
{
    CharLinkedList *l = newCharList();
    int predicate = 1;
    char_list_push_item(l, "Hola");
    char_list_push_item(l, " como");
    char_list_delete_item(l, " como");
    CharNode *aux = l->first;
    aux = aux->next;
    predicate &= (aux == NULL);
    char_list_delete_item(l, "Hola");
    aux = l->first;
    predicate &= (aux == NULL);
    char_free_list(l);
    return predicate;
}

int test_char_list_search_item(){
    CharLinkedList *l = newCharList();
    char_list_push_item(l, "Hola");
    char_list_push_item(l, " como");
    char_list_push_item(l, "estas");
    return char_list_search_item(l,"Hola")&&char_list_search_item(l," como")&&char_list_search_item(l,"estas")&&!char_list_search_item(l,"pina");
}

// int test_char_stringify_list()
// {
//     CharLinkedList *l = newCharList();
//     list_push_item(l, 1);
//     list_push_item(l, 2);
//     list_push_item(l, 3);
//     char *string = stringify_list(l);
//     printf("List example: ");
//     print_list(l);
//     free_list(l);
//     return !strcmp(string, "1 2 3\n");
// }
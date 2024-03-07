#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "int_list.h"
#include "../../nodes/int_node.h"

IntLinkedList *newList()
{
    IntLinkedList *l = malloc(sizeof(IntLinkedList));
    if (l == NULL)
    {
        printf("There was an error creating the list\n");
        exit(1);
    }
    l->first = NULL;
    l->size = 0;
    return l;
}

void list_push_item(IntLinkedList *l, int value)
{
    IntNode *n = malloc(sizeof(IntNode));
    if (n == NULL)
    {
        printf("Mistake at insert elements to the list\n");
        exit(1);
    }
    n->next = NULL;
    n->value = value;
    if (l->first == NULL)
    {
        l->first = n;
    }
    else
    {
        IntNode *aux = l->first;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = n;
    }
    l->size++;
}

void list_add_item(IntLinkedList *l, int value, int index)
{
    if (index > l->size)
    {
        printf("Indicated index is greater than list size");
        return;
    }
    IntNode *n = malloc(sizeof(IntNode));
    if (n == NULL)
    {
        printf("Mistake at insert elements to the list\n");
        exit(1);
    }
    n->value = value;
    if (l->first == NULL)
    {
        n->next = NULL;
        l->first = n;
    }
    else if (index == 0)
    {
        n->next = l->first;
        l->first = n;
    }
    else
    {
        IntNode *aux = l->first;
        for (int i = 1; i < index; i++)
        {
            aux = aux->next;
        }
        n->next = aux->next;
        aux->next = n;
    }
    l->size++;
}

void list_insert_item(IntLinkedList *l, int value)
{
    IntNode *n = malloc(sizeof(IntNode));
    if (n == NULL)
    {
        printf("Mistake at insert elements to the list\n");
        exit(1);
    }
    n->value = value;
    n->next = l->first;
    l->first = n;
    l->size++;
}

void list_delete_item(IntLinkedList *l, int value)
{
    if (l->first == NULL)
    {
        printf("The list are empty\n");
        return;
    }
    else
    {
        IntNode *aux = l->first;
        IntNode *ant = NULL;
        while (aux != NULL && aux->value != value)
        {
            ant = aux;
            aux = aux->next;
        }
        if (aux == NULL)
        {
            printf("The value doesn't exists %d\n", value);
            return;
        }
        if (ant == NULL)
        { // The value is in the first node
            l->first = aux->next;
        }
        else
        {
            ant->next = aux->next;
        }
        free(aux);
        l->size--;
    }
}

int *list_to_array(IntLinkedList *l)
{
    int *arr = malloc(sizeof(int) * l->size);
    IntNode *node = l->first;
    for (int i = 0; i < l->size; i++)
    {
        arr[i] = node->value;
        node = node->next;
    }
    return arr;
}

char *stringify_list(IntLinkedList *l)
{
    char *str = malloc(sizeof(char) * l->size * 12);
    str[0] = '\0';
    IntNode *node = l->first;
    for (int i = 0; node != NULL; i++)
    {
        sprintf(str + strlen(str), "%d ", node->value);
        node = node->next;
    }
    sprintf(str + strlen(str) - 1, "\n"); // Replacing the last blankspace with a line jump
    return str;
}

void print_list(IntLinkedList *l)
{
    printf(stringify_list(l));
}

void free_list(IntLinkedList *l)
{
    if (l->first == NULL)
    {
        free(l);
        return;
    }
    else
    {
        IntNode *aux = l->first;
        IntNode *next;
        while (aux != NULL)
        {
            next = aux->next;
            free(aux);
            aux = next;
        }
        free(l);
    }
}
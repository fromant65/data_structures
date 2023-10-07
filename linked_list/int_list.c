#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"
#include "../nodes/int_node.h"

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


void push_item(IntLinkedList *l, int value)
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

void add_item(IntLinkedList *l, int value, int index)
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
    else
    {
        IntNode *aux = l->first;
        for (int i = 0; i < index; i++)
        {
            aux = aux->next;
        }
        n->next = aux->next;
        aux->next = n;
    }
    l->size++;
}

void delete_item(IntLinkedList *l, int value)
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

void print_list(IntLinkedList *l)
{
    if (l == NULL)
    {
        printf("The list is not defined\n");
        return;
    }
    if (l->first == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    IntNode *aux = l->first;
    while (aux != NULL)
    {
        printf("%d, ", aux->value);
        aux = aux->next;
    }
    printf("\n");
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
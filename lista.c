#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

LinkedList *newList()
{
    LinkedList *l = malloc(sizeof(LinkedList));
    if (l == NULL)
    {
        printf("Error al crear la lista\n");
        exit(1);
    }
    l->first = NULL;
    l->size = 0;
    return l;
}

void push(LinkedList *l, int value)
{
    Node *n = malloc(sizeof(Node));
    if (n == NULL)
    {
        printf("Error al insertar en la lista\n");
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
        Node *aux = l->first;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = n;
    }
    l->size++;
}

void delete_item(LinkedList *l, int value)
{
    if (l->first == NULL)
    {
        printf("La lista esta vacia\n");
        return;
    }
    else
    {
        Node *aux = l->first;
        Node *ant = NULL;
        while (aux != NULL && aux->value != value)
        {
            ant = aux;
            aux = aux->next;
        }
        if (aux == NULL)
        {
            printf("No se encontro el valor %d\n", value);
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

void print_list(LinkedList *l)
{
    if (l->first == NULL)
    {
        printf("La lista esta vacia\n");
        return;
    }
    Node *aux = l->first;
    while (aux != NULL)
    {
        printf("%d, ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

void free_list(LinkedList *l)
{

    if (l->first == NULL)
    {
        free(l);
        return;
    }
    else
    {
        Node *aux = l->first;
        for (Node *next; aux != NULL; aux = next)
        {
            next = aux->next;
            free(aux);
        }
        free(l);
    }
}
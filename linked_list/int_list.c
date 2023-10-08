#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

char *stringify_list(IntLinkedList *l)
{
    int size = l->size * 12;
    char *str = malloc(size * sizeof(char));
    if (str == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    str[0] = '\0'; // Start with an empty string

    IntNode *current = l->first;
    while (current != NULL)
    {
        // Check if the string needs to be resized
        while (snprintf(NULL, 0, "%s%d ", str, current->value) >= size)
        {
            size *= 2;
            str = realloc(str, size * sizeof(char));
            if (str == NULL)
            {
                printf("Memory allocation failed\n");
                exit(1);
            }
        }

        // Append the current value to the string
        sprintf(str + strlen(str), "%d ", current->value);

        current = current->next;
    }

    // Add the newline at the end
    sprintf(str + strlen(str), "\n");

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
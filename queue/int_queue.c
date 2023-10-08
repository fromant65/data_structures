#include <stdio.h>
#include <stdlib.h>

#include "int_queue.h"

Queue *newQueue()
{
    Queue *q = malloc(sizeof(Queue));

    if (q == NULL)
    {
        printf("Mistake at create the Queue\n");
        exit(1);
    }
    q->first = NULL;
    q->last = NULL;

    return q;
}

void push(Queue *q, int value)
{
    Node *n = malloc(sizeof(Queue));

    if (n == NULL)
    {
        printf("Mistake at insert elements to the list\n");
        exit(1);
    }

    n->next = NULL;
    n->value = value;

    if (q->last == NULL)
    {
        q->first = n;
        q->last = n;
    }
    else
    {

        q->last->next = n;
        q->last = n;
    }

    q->size++;
}

void delete_item(Queue *q)
{
    if (q->first == NULL)
    {
        printf("The queue are empty\n");
        return;
    }

    Node *aux = q->first;

    q->first = q->first->next;
    q->size--;

    if (q->size == 0)
    {
        q->last = NULL;
    }

    free(aux);
}

void print_queue(Queue *q)
{
    if (q->first == NULL)
    {
        printf("The list are void\n");
        return;
    }

    Node *aux = q->first;
    while (aux != NULL)
    {
        printf("%d, ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}
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
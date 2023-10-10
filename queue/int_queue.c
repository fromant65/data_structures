#include <stdio.h>
#include <stdlib.h>

#include "../nodes/int_node.h"
#include "int_queue.h"

IntQueue *newQueue()
{
    IntQueue *q = malloc(sizeof(IntQueue));

    if (q == NULL)
    {
        printf("Mistake at create the Queue\n");
        exit(1);
    }
    q->first = NULL;
    q->last = NULL;
    q->size = 0;

    return q;
}

void queue_push_item(IntQueue *q, int value)
{
    IntNode *n = malloc(sizeof(IntQueue));

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

        IntNode *auxLastNext = q->last;
        auxLastNext->next = n;
        q->last = n;
    }

    q->size++;
}

void queue_delete_item(IntQueue *q)
{
    if (q->first == NULL)
    {
        printf("The queue are empty\n");
        return;
    }

    IntNode *aux = q->first;

    IntNode *auxFirstNext = q->first;
    q->first = auxFirstNext->next;
    q->size--;

    if (q->size == 0)
    {
        q->last = NULL;
    }

    free(aux);
}

void print_queue(IntQueue *q)
{
    if (q->first == NULL)
    {
        printf("The list are void\n");
        return;
    }

    IntNode *aux = q->first;
    while (aux != NULL)
    {
        printf("%d, ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

void free_queue(IntQueue *q)
{
    if (q->first == NULL)
    {
        free(q);
        return;
    }
    else
    {
        IntNode *aux = q->first;
        IntNode *next;
        while (aux != q->last)
        {
            next = aux->next;
            free(aux);
            aux = next;
        }
        free(q);
    }
}
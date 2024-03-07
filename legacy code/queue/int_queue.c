#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int *queue_to_array(IntQueue *q)
{
    int *arr = malloc(sizeof(int) * q->size);
    IntNode *node = q->first;
    for (int i = 0; i < q->size; i++)
    {
        arr[i] = node->value;
        node = node->next;
    }
    return arr;
}

char *stringify_queue(IntQueue *q)
{
    char *str = malloc(sizeof(char) * q->size * 12);
    str[0] = '\0';
    IntNode *node = q->first;
    for (int i = 0; node != NULL; i++)
    {
        sprintf(str + strlen(str), "%d ", node->value);
        node = node->next;
    }
    sprintf(str + strlen(str) - 1, "\n"); // Replacing the last blankspace with a line jump
    return str;
}

void print_queue(IntQueue *q)
{
    if (q->first == NULL)
    {
        printf("The queue is empty\n");
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
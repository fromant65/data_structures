#include <stdio.h>
#include <stdlib.h>

#include "../nodes/int_node.h"
#include "int_queue.h"

int test_new_queue();
int test_push_item_queue();
int test_delete_item_queue();

void test_queue()
{
    printf("Testing newQueue function...\n");
    int t_new_queue = test_new_queue();
    printf("Testing push_item function...\n");
    int t_push_item = test_push_item_queue();
    printf("Testing delete_item function...\n");
    int t_delete_item = test_delete_item_queue();

    int test_result = t_new_queue && t_push_item;
    if (test_result)
    {
        printf("Tests for queue have passed successfully\n");
    }
    else
    {
        if (!t_new_queue)
        {
            printf("new_queue function not wotking properly\n");
        }
        if (!t_push_item)
        {
            printf("push_item function not wotking properly\n");
        }
        if (!t_delete_item)
        {
            printf("delete_item function not wotking properly\n");
        }
    }
}

int test_new_queue()
{
    IntQueue *queue = newQueue();
    int predicate = (queue->first == NULL && queue->size == 0);

    free_queue(queue);
    return predicate;
}

int test_push_item_queue()
{
    IntQueue *queue = newQueue();
    int predicate = 1;

    queue_push_item(queue, 1);
    queue_push_item(queue, 2);

    IntNode *aux = queue->first;

    predicate &= (aux->value == 1);
    aux = aux->next;
    predicate &= (aux->value == 2);
    aux = aux->next;
    predicate &= (aux == NULL);
    free_queue(queue);

    return predicate;
}

int test_delete_item_queue()
{
    IntQueue *queue = newQueue();

    int predicate = 1;
    queue_push_item(queue, 1);
    queue_push_item(queue, 2);
    queue_push_item(queue, 3);

    IntNode *aux = queue->first;
    aux = aux->next;

    queue_delete_item(queue);

    predicate &= (aux->value == 2);

    queue_delete_item(queue);

    aux = queue->first;
    IntNode *aux2 = queue->last;

    predicate &= (aux->value == 3 && aux->value == aux2->value);
    queue_delete_item(queue);

    aux = queue->first;

    predicate &= (aux == NULL);

    free_queue(queue);
    return predicate;
}
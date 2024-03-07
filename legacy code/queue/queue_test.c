#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../nodes/int_node.h"
#include "queue_test.h"
#include "int_queue.h"

void test_new_queue();
void test_push_item_queue();
void test_delete_item_queue();
void test_queue_to_array();
void test_stringify_queue();

void test_queue()
{
    printf("Testing newQueue function...\n");
    test_new_queue();
    printf("Testing push_item function...\n");
    test_push_item_queue();
    printf("Testing delete_item function...\n");
    test_delete_item_queue();
    printf("Testing queue_to_array function...\n");
    test_queue_to_array();
    printf("Testing stringify_queue function...\n");
    test_stringify_queue();
}

void test_new_queue()
{
    IntQueue *queue = newQueue();
    assert(queue->first == NULL && queue->size == 0);
    free_queue(queue);
}

void test_push_item_queue()
{
    IntQueue *queue = newQueue();
    queue_push_item(queue, 1);
    queue_push_item(queue, 2);
    IntNode *aux = queue->first;
    assert(aux->value == 1);
    aux = aux->next;
    assert(aux->value == 2);
    aux = aux->next;
    assert(aux == NULL);
    free_queue(queue);
}

void test_delete_item_queue()
{
    IntQueue *queue = newQueue();
    queue_push_item(queue, 1);
    queue_push_item(queue, 2);
    queue_push_item(queue, 3);
    IntNode *aux = queue->first;
    aux = aux->next;
    queue_delete_item(queue);
    assert(aux->value == 2);
    queue_delete_item(queue);
    aux = queue->first;
    IntNode *aux2 = queue->last;
    assert(aux->value == 3 && aux->value == aux2->value);
    queue_delete_item(queue);
    aux = queue->first;
    assert(aux == NULL);
    free_queue(queue);
}

void test_queue_to_array()
{
    IntQueue *q = newQueue();
    queue_push_item(q, 1);
    queue_push_item(q, 2);
    queue_push_item(q, 3);
    int *arr = queue_to_array(q);
    assert(arr[0] == 1 && arr[1] == 2 && arr[2] == 3);
}

void test_stringify_queue()
{
    IntQueue *q = newQueue();
    queue_push_item(q, 1);
    queue_push_item(q, 2);
    queue_push_item(q, 3);
    char *string = stringify_queue(q);
    printf("Queue example: ");
    print_queue(q);
    assert(strcmp(string, "1 2 3\n") == 0);
    free_queue(q);
}

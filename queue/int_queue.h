#ifndef INT_QUEUE_H
#define INT_QUEUE_H

#include "../nodes/int_node.h"

typedef struct
{
    IntNode *first;
    IntNode *last;
    int size;
} IntQueue;

IntQueue *newQueue();
void queue_push_item(IntQueue *q, int value); // add new elements to queue struct
void queue_delete_item(IntQueue *q);          // delete the first  element from queue struct
int *queue_to_array(IntQueue *q);             // returns an array with the queue data
char *stringify_queue(IntQueue *q);           // returns a string with the queue values separated by blankspaces
void print_queue(IntQueue *q);                // print the queue struct
void free_queue(IntQueue *q);

#endif
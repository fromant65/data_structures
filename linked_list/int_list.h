#ifndef LIST_H
#define LIST_H

#include "../nodes/int_node.h"

typedef struct
{
    IntNode *first;
    int size;
} IntLinkedList;

IntLinkedList *newList();
void push_item(IntLinkedList *l, int value);           // adds element to the end of the list
void add_item(IntLinkedList *l, int value, int index); // adds an element to the list on specified index
void delete_item(IntLinkedList *l, int value);         // deletes an element from the list
int *list_to_array(IntLinkedList *l);                  // Returns an array with the list data
char *stringify_list(IntLinkedList *l);                // Returns a string with the list data separated by blankspaces
void print_list(IntLinkedList *l);
void free_list(IntLinkedList *l);

#endif
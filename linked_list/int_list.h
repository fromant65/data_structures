#ifndef LIST_H
#define LIST_H

typedef struct
{
    struct Node *first;
    int size;
} IntLinkedList;

IntLinkedList *newList();
void push_item(IntLinkedList *l, int value);           // adds element to the end of the list
void add_item(IntLinkedList *l, int value, int index); // adds an element to the list on specified index
void delete_item(IntLinkedList *l, int value);         // deletes an element from the list
void print_list(IntLinkedList *l);
void free_list(IntLinkedList *l);

#endif
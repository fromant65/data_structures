#ifndef LIST_H
#define LIST_H

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    struct Node *first; // Use 'struct Node' instead of 'Node'
    int size;
} LinkedList;

LinkedList *newList();
void push(LinkedList *l, int value);        // adds an element to the list
void delete_item(LinkedList *l, int value); // deletes an element from the list
void print_list(LinkedList *l);
void free_list(LinkedList *l);

#endif
#ifndef CHAR_LIST_H
#define CHAR_LIST_H

#include "../../nodes/char_node.h"

typedef struct
{
    CharNode *first;
    int size;
} CharLinkedList;

CharLinkedList *newCharList();
void char_list_push_item(CharLinkedList *l, char* value);           // adds element to the end of the list
void char_list_add_item(CharLinkedList *l, char* value, int index); // adds an element to the list on specified index
void char_list_delete_item(CharLinkedList *l, char* value);         // deletes an element from the list
int char_list_search_item(CharLinkedList *l, char* value); // returns 1 if item is found, 0 otherwise
//char *char_stringify_list(CharLinkedList *l);                     // Returns a string with the list data separated by blankspaces
void char_print_list(CharLinkedList *l);
void char_free_list(CharLinkedList *l);

#endif
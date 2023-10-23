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
char *char_list_to_array(CharLinkedList *l);                       // Returns an array with the list data
char *char_stringify_list(CharLinkedList *l);                     // Returns a string with the list data separated by blankspaces
void char_print_list(CharLinkedList *l);
void char_free_list(CharLinkedList *l);

#endif
#include "int_list.h"

void linkedTest()
{
    IntLinkedList *l = newList();
    print_list(l);
    push_item(l, 10);
    print_list(l);
    add_item(l, 2, 0);
    print_list(l);
    add_item(l, 3, 1);
    print_list(l);
    delete_item(l, 4);
    print_list(l);
    delete_item(l, 10);
    print_list(l);
    free_list(l);
}
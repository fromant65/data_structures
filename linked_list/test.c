#include "list.h"

void linkedTest()
{
    LinkedList *l = newList();

    print_list(l);
    push(l, 1);
    print_list(l);
    push(l, 2);
    print_list(l);
    push(l, 3);
    print_list(l);
    push(l, 5);
    print_list(l);
    delete_item(l, 2);
    print_list(l);
    delete_item(l, 4);
    print_list(l);
    free_list(l);
}
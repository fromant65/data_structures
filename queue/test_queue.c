#include "int_queue.h"
void test_queue()
{
    Queue *q = newQueue();

    print_queue(q);

    push(q, 4);
    print_queue(q);

    push(q, 2);
    push(q, 8);
    print_queue(q);

    delete_item(q);
    print_queue(q);
}
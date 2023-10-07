#include <stdio.h>
#include <stdlib.h>

#include "./queue/int_queue.h"

int main()
{
    Queue *q = newQueue();

    push(q, 4);
    print_queue(q);

    push(q, 6);
    push(q, 8);
    print_queue(q);
    return 0;
}
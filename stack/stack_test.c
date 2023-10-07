#include <stdio.h>
#include "int_stack.h"
#include "stack_test.h"
#include "../nodes/int_node.h"

void test_stack()
{
    IntStack *stack = newStack();
    printf("created stack\n");
    push(stack, 1);
    printf("pushed 1\n");
    push(stack, 2);
    printf("pushed 2\n");
    printf("popped %d\n", pop(stack));
    printf("popped %d\n", pop(stack));
    printf("popped %d\n", pop(stack));
    push(stack, 10);
    printf("pushed 10\n");
    push(stack, 20);
    printf("pushed 20\n");
    free_stack(stack);
}
#include <assert.h>
#include <stdio.h>
#include "int_stack.h"
#include "stack_test.h"
#include "../nodes/int_node.h"

void test_newStack();
void test_stack_push();
void test_stack_pop();

void test_stack()
{
    printf("Testing newStack function...\n");
    test_newStack();
    printf("Testing stack_push function...\n");
    test_stack_push();
    printf("Testing stack_pop function...\n");
    test_stack_pop();
}

void test_newStack()
{
    IntStack *stack = newStack();
    assert(stack->last == NULL);
    free_stack(stack);
}

void test_stack_push()
{
    IntStack *stack = newStack();
    stack_push(stack, 1);
    IntNode *last = stack->last;
    assert(last->value == 1);
    free_stack(stack);
}

void test_stack_pop()
{
    IntStack *stack = newStack();
    stack_push(stack, 10);
    stack_push(stack, 20);
    int pop = stack_pop(stack);
    IntNode *last = stack->last;
    assert(pop == 20 && last->value == 10);
    free_stack(stack);
}

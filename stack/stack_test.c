#include <stdio.h>
#include "int_stack.h"
#include "stack_test.h"
#include "../nodes/int_node.h"

int test_newStack();
int test_stack_push();
int test_stack_pop();

void test_stack()
{
    printf("Testing newStack function...\n");
    int t_new_stack = test_newStack();
    printf("Testing stack_push function...\n");
    int t_stack_push = test_stack_push();
    printf("Testing stack_pop function...\n");
    int t_stack_pop = test_stack_pop();
    int test_result = t_new_stack && t_stack_push && t_stack_pop;
    if (test_result)
    {
        printf("Tests for stack have passed successfully\n");
    }
    else
    {
        printf("Tests have failed:\n");
        if (!t_new_stack)
        {
            printf("NewStack function not working properly\n");
        }
        if (!t_stack_push)
        {
            printf("stack_Push function not working properly\n");
        }
        if (!t_stack_pop)
        {
            printf("stack_Pop function not working properly\n");
        }
    }
}

int test_newStack()
{
    int predicate = 1;
    IntStack *stack = newStack();
    predicate &= (stack->last == NULL);
    return predicate;
}

int test_stack_push()
{
    int predicate = 1;
    IntStack *stack = newStack();
    stack_push(stack, 1);
    IntNode *last = stack->last;
    predicate &= (last->value == 1);
    free_stack(stack);
    return predicate;
}

int test_stack_pop()
{
    int predicate = 1;
    IntStack *stack = newStack();
    int first_stack_pop = stack_pop(stack);
    predicate &= (first_stack_pop == 0);
    stack_push(stack, 10);
    stack_push(stack, 20);
    int second_stack_pop = stack_pop(stack);
    IntNode *last = stack->last;
    predicate &= (second_stack_pop == 20 && last->value == 10);
    free_stack(stack);
    return predicate;
}
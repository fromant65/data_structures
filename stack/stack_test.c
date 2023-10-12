#include <stdio.h>
#include "int_stack.h"
#include "stack_test.h"
#include "../nodes/int_node.h"

int test_newStack();
int test_push();
int test_pop();

void test_stack()
{
    printf("Testing newStack function...\n");
    int t_new_stack = test_newStack();
    printf("Testing push function...\n");
    int t_push = test_push();
    printf("Testing pop function...\n");
    int t_pop = test_pop();
    int test_result = t_new_stack && t_push && t_pop;
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
        if (!t_push)
        {
            printf("Push function not working properly\n");
        }
        if (!t_pop)
        {
            printf("Pop function not working properly\n");
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

int test_push()
{
    int predicate = 1;
    IntStack *stack = newStack();
    push(stack, 1);
    IntNode *last = stack->last;
    predicate &= (last->value == 1);
    free_stack(stack);
    return predicate;
}

int test_pop()
{
    int predicate = 1;
    IntStack *stack = newStack();
    int first_pop = pop(stack);
    predicate &= (first_pop == 0);
    push(stack, 10);
    push(stack, 20);
    int second_pop = pop(stack);
    IntNode *last = stack->last;
    predicate &= (second_pop == 20 && last->value == 10);
    free_stack(stack);
    return predicate;
}
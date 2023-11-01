#ifndef STACK_H
#define STACK_H

#include "../nodes/int_node.h"

typedef struct
{
    IntNode *last;
} IntStack;

IntStack *newStack();
void stack_push(IntStack *stack, int value); // adds a value to the stack
int stack_pop(IntStack *stack);              // removes the last value from the stack and returns it
void free_stack(IntStack *stack);            // removes all elements from the stack and deletes it

#endif
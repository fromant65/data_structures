#ifndef STACK_H
#define STACK_H

typedef struct
{
    struct IntNode *last;
} IntStack;

IntStack *newStack();
void push(IntStack *stack, int value); // adds a value to the stack
int pop(IntStack *stack);              // removes the last value from the stack and returns it
void free_stack(IntStack *stack);      // removes all elements from the stack and deletes it

#endif
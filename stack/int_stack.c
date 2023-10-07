#include <stdio.h>
#include <stdlib.h>
#include "int_stack.h"
#include "../nodes/int_node.h"

IntStack *newStack()
{
    IntStack *stack = malloc(sizeof(IntStack));
    if (stack == NULL)
    {
        printf("There was an error creating the stack\n");
        exit(1);
    }
    stack->last = NULL;
    return stack;
}

void push(IntStack *stack, int value)
{
    IntNode *node = malloc(sizeof(IntNode));
    if (node == NULL)
    {
        printf("There was an error adding the value\n");
        exit(1);
    }
    node->next = stack->last;
    node->value = value;
    stack->last = node;
}

int pop(IntStack *stack)
{
    if (stack->last == NULL)
    {
        printf("There are no items to pop\n");
        return NULL;
    }
    IntNode *aux = stack->last;
    int value = aux->value;
    stack->last = aux->next;
    free(aux);
    return value;
}

void free_stack(IntStack *stack)
{
    IntNode *aux;
    while (stack->last != NULL)
    {
        aux = stack->last;
        stack->last = aux->next;
        free(aux);
    }
    free(stack);
}

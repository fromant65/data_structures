#ifndef __STACK_H__
#define __STACK_H__

typedef struct _node{
    void* data;
    struct _node* next;
}GNode;

typedef GNode* Stack;
typedef void* (*CopyFunction)(void*);
typedef void (*DestructorFunction)(void*);
typedef void (*ParsingFunction)(void*);

/**
 * @brief Creates an empty stack
 * @return NULL
*/
Stack newStack();

/**
 * @brief Liberates all the memory used by the stack
*/
void StackDestroy(Stack, DestructorFunction);

/**
 * @return 1 if the stack is empty, 0 otherwise
*/
int StackEmpty(Stack);

/**
 * @brief Adds an element at the top of the stack
 * @return The stack with the new element at the top
*/
Stack StackPush(Stack, void*, CopyFunction);

/**
 * @brief Deletes the top element of the stack
 * @return The stack without its top element
*/
Stack StackPop(Stack, DestructorFunction d);

/**
 * @brief maps the ParsingFunction to all the elements of the stack
*/
void StackMap(Stack, ParsingFunction);

#endif
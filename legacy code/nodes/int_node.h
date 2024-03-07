#ifndef INT_NODE_H
#define INT_NODE_H

typedef struct IntNode_
{
    int value;
    struct IntNode_ *next;
} IntNode;

#endif
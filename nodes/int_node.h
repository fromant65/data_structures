#ifndef INT_NODE_H
#define INT_NODE_H

typedef struct
{
    int value;
    struct IntNode *next;
} IntNode;

#endif
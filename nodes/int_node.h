#ifndef INT_NODE_H
#define INT_NODE_H

typedef struct IntNode IntNode;

struct IntNode
{
    int value;
    IntNode *next;
};

#endif
#ifndef CHAR_NODE_H
#define CHAR_NODE_H

typedef struct CharNode_
{
    char *value;
    struct CharNode_ *next;
} CharNode;

#endif
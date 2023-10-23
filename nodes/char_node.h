#ifndef CHAR_NODE_H
#define CHAR_NODE_H

typedef struct CharNode CharNode;

struct CharNode{
    char* value;
    CharNode* next;
};


#endif
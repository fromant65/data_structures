#ifndef SLL_H
#define SLL_H
#include "../object/object.h"
#include "../types/types_functions.h"

typedef struct _NodeSLL{
    Object data;
    struct _NodeSLL *next;
}NodeSLL;

typedef struct{
    NodeSLL *first;
    NodeSLL *last;
    size_t length;
    enum Types type;
}SinglyLinkedList;

NodeSLL *newNodeSLL(Object obj, NodeSLL* next);
SinglyLinkedList newSinglyLinkedList(enum Types type);
void SLLPush(SinglyLinkedList* list, Object obj);
void SLLPop(SinglyLinkedList* list);
void SLLUnshift(SinglyLinkedList* list, Object obj); //Adds an object in the first position
void SLLShift(SinglyLinkedList* list); //Removes the element in the first position
void SLLPrint(SinglyLinkedList list);
void NodeSLLFree(NodeSLL *node);
void SLLFree(SinglyLinkedList* list);

#endif
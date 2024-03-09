#include "sll.h"
#include <stdio.h>

NodeSLL *newNodeSLL(Object obj, NodeSLL* next){
    NodeSLL *node = malloc(sizeof(NodeSLL));
    if(node == NULL){
        printf("Cannot alloc new node for SLL\n");
        return NULL;
    }
    node->data = obj;
    node->next = next;
    return node;
}

SinglyLinkedList newSinglyLinkedList(enum Types type){
    SinglyLinkedList list = {NULL, NULL, 0, type};
    return list;
}

void SLLPush(SinglyLinkedList* list, Object obj){
    NodeSLL *node = newNodeSLL(obj,NULL);
    if(node==NULL) return;
    if(list->length == 0){    
        list->first = node;
        list->last = node;
    }else{
        list->last->next = node;
        list->last = node;
    }
    list->length ++;
}

void SLLPop(SinglyLinkedList* list){
    if(list->length == 0){
        return;
    }else if(list->length == 1){
        NodeSLLFree(list->last);
        list->first=NULL;
        list->last =NULL;
    }
    else{
        NodeSLL *temp = list->first;
        while(temp->next->next!=NULL){ //advance up to the second to last node
            temp = temp->next;
        }
        NodeSLLFree(temp->next);
        temp->next=NULL;
        list->last = temp;
    }
    list->length--;
}

void SLLUnshift(SinglyLinkedList* list, Object obj){
    NodeSLL *node = newNodeSLL(obj,list->first);
    list->first = node;
    if(list->length == 0) list->last = node;
    list->length ++;
}

void SLLShift(SinglyLinkedList* list){
    NodeSLL* temp = list->first;
    list->first = temp->next;
    NodeSLLFree(temp);
    list->length --;
}

void SLLPrint(SinglyLinkedList list){
    NodeSLL *temp = list.first;
    while(temp->next!=NULL){
        printObject(temp->data, " -> ");
        temp = temp->next;
    }
    if(temp->next==NULL){
        printObject(temp->data, "\n");
    }
}

void NodeSLLFree(NodeSLL *node){
    freeObjectData(node->data);
    free(node);
}

void SLLFree(SinglyLinkedList* list){
    NodeSLL *temp = list->first;
    while(temp!=NULL){
        NodeSLL *freeing = temp;
        temp = temp->next;
        NodeSLLFree(freeing);
    }
}
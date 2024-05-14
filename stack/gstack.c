#include "gstack.h"
#include <stdlib.h>

Stack newStack(){
    return NULL;
}

void StackDestroy(Stack s, DestructorFunction d){
    while(s!=NULL){
        s=StackPop(s,d);
    }
}

int StackEmpty(Stack s){
    return s==NULL;
}

Stack StackPush(Stack s, void* data, CopyFunction c){
    Stack top = s;
    GNode* newTop= malloc(sizeof(GNode));
    newTop->data=c(data);
    newTop->next=top;
    return newTop;
}

Stack StackPop(Stack s, DestructorFunction d){
    if(StackEmpty(s)) return NULL;
    Stack newTop = s->next;
    d(s->data);
    free(s);
    return newTop;
}

void StackMap(Stack s, ParsingFunction d){
    while(s!=NULL){
        d(s->data);
        s=s->next;
    }
}

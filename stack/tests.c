#include "gstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void printStackNode(void* data){
    printf("%d ", *(int*)data);
}
void* copyInt_(void* data){
    int* newData = malloc(sizeof(int));
    *newData = *(int*)data;
    return newData;
}

void destroyInt_(void* data){
    free(data);
}

void testStack(){
    printf("Testing Stack data structure...\n");    
    int d1=10;
    int d2=1;
    int d3=5;
    int d4=16;
    int d5=9;
    int d6=0;
    int data[6]={d1,d2,d3,d4,d5,d6};
    Stack stack = newStack();
    for(int i = 0;i<4;i++){
        stack = StackPush(stack,&data[i],copyInt_);
    }
    assert(*(int*)(stack->data)==16);
    stack= StackPop(stack,destroyInt_);
    assert(*(int*)(stack->data)==5);
    assert(StackEmpty(stack)==0 && StackEmpty(NULL));
    StackMap(stack, printStackNode);
    StackDestroy(stack, destroyInt_);
    printf("End of Stack tests\n");

}
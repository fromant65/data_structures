#include "tests.h"
#include "glist.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printNode(void* data){
    printf("%d ", *(int*)data);
}
void* copyInt(void* data){
    int* newData = malloc(sizeof(int));
    *newData = *(int*)data;
    return newData;
}

void destroyInt(void* data){
    free(data);
}

int even(void* data){
    return !(*(int*)data%2);
}

void testList(){
    printf("Testing List data structure...\n");    
    int d1=10;
    int d2=1;
    int d3=5;
    int d4=16;
    int d5=9;
    int d6=0;
    int data[6]={d1,d2,d3,d4,d5,d6};
    GList list = newGlist();
    for(int i = 0;i<4;i++){
        list = glistAdd(list,&data[i],copyInt);
    }
    assert(*(int*)(list->data)==16);
    list= glistDelete(list,destroyInt);
    assert(*(int*)(list->data)==5);
    assert(glistEmpty(list)==0 && glistEmpty(NULL));
    GList filteredList = glistFilter(list, copyInt, even);
    glistMap(filteredList, printNode);
    assert(*(int*)(filteredList->data)==10);
    glistFree(list, destroyInt);
    glistFree(filteredList, destroyInt);
    printf("End of List tests\n");
}
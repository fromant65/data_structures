#include "tests.h"
#include "gqueue.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* copyInt__(void* data){
    int* p = malloc(sizeof(int));
    memcpy(p,data,sizeof(int));
    return p;
}

void destroyInt__(void* data){
    free(data);
}

void testQueue(){
    printf("Testing Queue data structure...\n");    
    int d1=10;
    int d2=1;
    int d3=5;
    int d4=16;
    int d5=9;
    int d6=0;
    int data[6]={d1,d2,d3,d4,d5,d6};
    Queue queue = newQueue(10);
    for(int i = 0;i<4;i++){
        queue = enQueue(queue,copyInt__(&data[i]));
    }
    assert(*(int*)QueueStart(queue)==10);
    queue= deQueue(queue, destroyInt__);
    assert(*(int*)QueueStart(queue)==1);
    Queue new_queue=newQueue(10);
    assert(QueueEmpty(queue)==0 && QueueEmpty(new_queue));
    destroyQueue(queue,destroyInt__);
    destroyQueue(new_queue,destroyInt__);
    printf("End of Queue tests\n");
}
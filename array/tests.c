#include "tests.h"
#include "garray.h"
#include <assert.h>
#include <stdio.h>

int comp(void* a, void* b){
    int da= *(int*)a;
    int db= *(int*)b;
    return da<db?-1:da>db?1:0;
}

void printint(void* a){
    printf("%d ", *(int*)a);
}

void freePila(void*a){
    printf("freeing %d\n", *(int*)a);
}

void testArray(){
    printf("Testing Array data structure...\n");    
    int d1=10;
    int d2=1;
    int d3=5;
    int d4=16;
    int d5=9;
    int d6=0;
    int data[6]={d1,d2,d3,d4,d5,d6};
    GArray arr = newGArray();
    for(int i = 0;i<4;i++){
        arr = GArrayPush(arr,&data[i]);
    }
    assert(*(int*)(arr.data)[0]==10 && *(int*)arr.data[3]==16);
    //GArrayMap(arr, printint); printf("\n");
    arr = GArrayPop(arr, freePila);
    assert(arr.last_index==3);
    //GArrayMap(arr, printint); printf("\n");
    arr = GArrayInsert(arr, 1, &data[4]);
    assert(*(int*)(arr.data)[1]==9);
    //GArrayMap(arr, printint); printf("\n");
    arr = GArrayUpdate(arr, 0, &data[5], freePila);
    assert(*(int*)(arr.data)[0]==0);
    //GArrayMap(arr, printint); printf("\n");
    arr = GArrayDelete(arr,3,freePila);
    assert(arr.last_index==3);
    //GArrayMap(arr, printint); printf("\n");
    //Doesn't work
    //arr = GArraySort(arr, comp);
    //GArrayMap(arr, printint); printf("\n");
    printf("End of Array tests\n");
}
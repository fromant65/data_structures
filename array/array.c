#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array newArray(enum Types type){
    size_t size = 256;
    Object* data = malloc(sizeof(Object)*size);
    Array arr = {data, 0, size, type};
    return arr;
}

void arrayPush(Array* arr, Object obj){
    if(arr->length<arr->max_size){
        arr->data[arr->length] = obj;
        arr->length++;
    }else{
        arrayExtend(arr);
        arrayPush(arr, obj);
    }
}
void arrayPop(Array* arr){
    if(arr->length<arr->max_size/2){
        arrayShrink(arr);
    }
    freeObjectData(arr->data[arr->length-1]);
    arr->length--;
}

void arrayInsert(Array *arr, int index, Object obj){
    if(index > arr->length || index < 0) return;
    if(arr->length<arr->max_size){
        for(int i = arr->length-1; i>=index; i--){
            arr->data[i+1]=arr->data[i];
        }
        arr->data[index]=obj;
        arr->length++;
    }else{
        arrayExtend(arr);
        arrayInsert(arr, index, obj);
    }
}

void arrayDelete(Array *arr, int index){
    if(index >= arr->length || index < 0) return;
    freeObjectData(arr->data[index]);
    for(int i = index; i<arr->length; i++){
        arr->data[i]=arr->data[i+1];
    }
    arr->length--;
}
void arrayExtend(Array *arr){
    arr->max_size*=2;
    arr->data = realloc(arr->data, sizeof(Object)*arr->max_size);
}

void arrayShrink(Array *arr){
    arr->max_size/=2;
    arr->data = realloc(arr->data, sizeof(Object)*arr->max_size);
}

void arrayPrint(Array arr){
    for(int i=0; i<arr.length; i++){
        printObject(arr.data[i]," ");
    }
    printf("\n");
}

void arrayFree(Array *arr){
    for(int i = 0; i<arr->length;i++){
        freeObjectData(arr->data[i]);
    }
    free(arr->data);
}
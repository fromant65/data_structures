#include "object.h"
#include <stdlib.h>
#include <stdio.h>

void* readData(enum Types type);

/**
 * Creates an Object instance with the provided type and data and returns it
 * if no data has been provided (data == NULL), the function reads the data
*/
Object newObject(enum Types type, void* data){
    size_t size = getTypeSize(type);
    bool is_data_static = true;
    if(size == 0){
        Object o = {NULL, 0, -1};
        printf("The provided data type is not valid: %d", type);
        return o;
    }
    if(data==NULL){
        data = readData(type);
        is_data_static = false;
    }
    Object o={data, size, type, is_data_static};
    return o;
}

void printObject(Object obj, char* separator){
    if(obj.ref==NULL){
        printf("Null object\n");
        return;
    }
    printingFunctions[obj.type](obj.ref, separator);
}

void freeObjectData(Object obj){
    if(obj.ref==NULL || obj.is_data_static){
        return;
    }
    freeType(obj.type)(obj.ref);
}

void* readData(enum Types type){
    return readingFunctions[type]();
}

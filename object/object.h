#ifndef OBJECT_H
#define OBJECT_H
#include <stdlib.h>
#include "../types/types_functions.h"
#include <stdbool.h>

typedef struct{
    void* ref; // points to the memory address of the data
    size_t size; // size of the object
    enum Types type; // defines the type of the object
    bool is_data_static; // if true, the data is on the stack; if false, the data is on the heap
}Object;

size_t getTypeSize(enum Types type);
Object newObject(enum Types type, void* data);
void printObject(Object obj, char* separator);
void freeObjectData(Object obj);

#endif
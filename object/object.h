#ifndef OBJECT_H
#define OBJECT_H
#include <stdlib.h>
#include "../types/types_functions.h"

typedef struct{
    void* ref; // points to the memory address of the data
    size_t size; // size of the object
    enum Types type; // defines the type of the object
}Object;

size_t getTypeSize(enum Types type);
Object newObject(enum Types type, void* data);
void printObject(Object obj);
void freeObjectData(Object obj);

#endif
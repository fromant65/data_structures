#ifndef ARRAY_H
#define ARRAY_H
#include "../object/object.h"
#include "../types/types_functions.h"

typedef struct{
    Object* data;
    size_t length;
    size_t max_size;
    enum Types type;
}Array;

Array newArray(enum Types type);
void arrayPush(Array*, Object);
void arrayPop(Array*);
void arrayInsert(Array*, int, Object);
void arrayDelete(Array*, int);
void arrayExtend(Array*);
void arrayShrink(Array*);
void arrayPrint(Array);
void arrayFree(Array*);

#endif
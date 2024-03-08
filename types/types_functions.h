#ifndef TYPES_FUNCTIONS_H
#define TYPES_FUNCTIONS_H
#include <stdlib.h>

enum Types{
    INT,
    DOUBLE,
    CHAR,
    STRING
};

// Get size
size_t getTypeSize(enum Types size);
// Reading functions
void* readInt();
void* readDouble();
void* readChar();
void* readString();
// Writing functions
void printInt(void*);
void printDouble(void*);
void printChar(void*);
void printString(void*);
// Freeing functions
typedef void (*FreeingFunction)(void*);
FreeingFunction freeType(enum Types type);
void freeStaticType(void*);
void freeStringType(void*);
// Function arrays - The arrays are declared in the order of the enum Types declaration
typedef void* (*ReadFunction)();
typedef void (*PrintFunction)(void*);
extern ReadFunction readingFunctions[];
extern PrintFunction printingFunctions[];

#endif
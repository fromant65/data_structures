#include <stdio.h>
#include <stdlib.h>
#include "types_functions.h"
#include "../object/object.h"

size_t getTypeSize(enum Types type){
    switch(type){
        case INT:
            return sizeof(int);
        case DOUBLE:
            return sizeof(double);
        case CHAR:
            return sizeof(char);
        case STRING:
            return sizeof(char*);
        default:
            return 0;
    }
}

/**
 * Type reading functions
 * Each one reads a variable form their type and returns a void pointer to it
*/
void* readInt(){
    int* data = malloc(sizeof(int));
    scanf("%d", data);
    return data;
}

void* readDouble(){
    double* data = malloc(sizeof(double));
    scanf("%lf", data);
    return data;
}

void* readChar(){
    char* data = malloc(sizeof(char));
    scanf(" %c", data);
    return data;
}

void* readString(){
    int i=0, size = 256;
    char c=getchar();
    char** string = malloc(sizeof(char*));
    *string = malloc(sizeof(char)*size);
    do{
        if(c!='\n') (*string)[i++]=c;
        if(i>=size){
            size*=2;
            char* temp = realloc(*string, sizeof(char)*size);
            if (temp == NULL) {
                free(*string);
                *string = NULL;
                return NULL;
            }
            *string = temp;
        }
    }while((c=getchar())!='\n');
    (*string)[i]='\0';
    return string;
}

/**
 * Type printing functions
 * Each one takes a void pointer for a variable of their type and printf's it with a line break
*/

void printInt(void* ref, char* separator){
    char line_break[] = "\n";
    if(separator==NULL) separator = line_break;

    printf("%d%s", *(int*)(ref), separator);
}

void printDouble(void* ref, char* separator){
    char line_break[] = "\n";
    if(separator==NULL) separator = line_break;

    printf("%lf%s", *(double*)(ref), separator);
}

void printChar(void* ref, char* separator){
    char line_break[] = "\n";
    if(separator==NULL) separator = line_break;
    printf("%c%s", *(char*)(ref), separator);
}

void printString(void* ref, char* separator){
    char line_break[] = "\n";
    if(separator==NULL) separator = line_break;
    printf("%s%s", *(char**)(ref), separator);
}

FreeingFunction freeType(enum Types type){
    switch(type){
        case INT:
            return freeStaticType;
        case DOUBLE:
            return freeStaticType;
        case CHAR:
            return freeStaticType;
        case STRING:
            return freeStringType;
        default:
            return freeStaticType;
    }
}

void freeStaticType(void* ptr){
    free(ptr);
}

void freeStringType(void* ptr){
    char* string = *(char**)ptr;
    free(string);
    free(ptr);
}

ReadFunction readingFunctions[]={readInt, readDouble, readChar, readString};
PrintFunction printingFunctions[]={printInt, printDouble, printChar, printString};
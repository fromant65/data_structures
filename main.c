#include <stdio.h>
#include <stdlib.h>
#include "object/object.h"
#include "array/array.h"
#include "singly_linked_list/sll.h"
int main(){
/*
    int i = 5;
    double f = 9.2;
    char c = 'K';
    char *s = malloc(sizeof(char)*256);
    s[0] = 'A';
    s[1] = 'B';
    s[2] = 'C';
    s[3] = '\0';
    Object c1 = newObject(INT,&i);
    Object c2 = newObject(DOUBLE,&f);
    Object c3 = newObject(CHAR,&c);
    Object c4 = newObject(STRING,&s);
    Object c5 = newObject(INT,NULL);
    Object c6 = newObject(DOUBLE,NULL);
    Object c7 = newObject(CHAR,NULL);
    Object c8 = newObject(STRING,NULL);
    printf("\n");
    printObject(c1);
    printObject(c2);
    printObject(c3);
    printObject(c4);
    printf("int: ");
    printObject(c5);
    printf("double: ");
    printObject(c6);
    printf("char: ");
    printObject(c7);
    printf("string: ");
    printObject(c8);
    free(s);
    freeObjectData(c1);
    freeObjectData(c2);
    freeObjectData(c3);
    freeObjectData(c4);
    freeObjectData(c5);
    freeObjectData(c6);
    freeObjectData(c7);
    freeObjectData(c8);
*/
/*
    Array arr = newArray(INT);
    for(int i = 0; i<8; i++){
        Object o = newObject(arr.type,NULL);
        arrayPush(&arr,o);
    }
    arrayPrint(arr);
    arrayPop(&arr);
    arrayPrint(arr);
    int x = -10;
    Object o = newObject(arr.type, &x);
    arrayInsert(&arr, 4, o);
    arrayPrint(arr);
    arrayDelete(&arr, 2);
    arrayPrint(arr);
*/
    SinglyLinkedList l = newSinglyLinkedList(INT);
    for(int i = 0; i<4; i++){
        Object o = newObject(l.type,NULL);
        SLLPush(&l,o);
    }
    SLLPrint(l);
    int x = -10;
    Object o = newObject(l.type, &x);
    SLLUnshift(&l, o);
    SLLPrint(l);
    SLLShift(&l);
    SLLPrint(l);
    SLLPop(&l);
    SLLPrint(l);
    return 0;
}
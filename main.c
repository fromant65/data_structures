#include <stdio.h>
#include <stdlib.h>
#include "object/object.h"
int main(){
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
    freeObjectData(c5);
    freeObjectData(c6);
    freeObjectData(c7);
    freeObjectData(c8);
    return 0;
}
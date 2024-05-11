#include "tests.h"
#include "object.h"
#include <assert.h>
#include <string.h>

void newObjectTest(){
    // Declaring values
    int d1 = 5;
    double d2 = 7.4;
    char d3 = 'a';
    char *d4 = "hello world";
    // Declaring objects
    Object o1 = newObject(INT, &d1);
    Object o2 = newObject(DOUBLE, &d2);
    Object o3 = newObject(CHAR, &d3);
    Object o4 = newObject(STRING, &d4);
    // Object assertions to test if the data has been set properly
    assert(*(int*)o1.ref==5);
    assert(*(double*)o2.ref==7.4);
    assert(*(char*)o3.ref=='a');
    assert(strcmp(*(char**)o4.ref, "hello world")==0);
    // freeing objects
    freeObjectData(o1);
    freeObjectData(o2);
    freeObjectData(o3);
    freeObjectData(o4);
}
#include "../types/types_functions.h"
#include "array.h"
#include "tests.h"
#include <assert.h>

void ArrayTest(){
    newArrayTest();
    arrayPushTest();
    arrayPopTest();
    arrayInsertTest();
    arrayDeleteTest();
    arrayExtendTest();
    arrayShrinkTest();
}

void newArrayTest(){
    Array intArr = newArray(INT);
    Array doubleArr = newArray(DOUBLE);
    Array charArr = newArray(CHAR);
    Array stringArr = newArray(STRING);
    assert(intArr.length == doubleArr.length && intArr.length == charArr.length && intArr.length == stringArr.length && intArr.length==0);
    assert(intArr.type == INT);
    assert(doubleArr.type == DOUBLE);
    assert(charArr.type == CHAR);
    assert(stringArr.type == STRING);
    arrayFree(&intArr);
    arrayFree(&doubleArr);
    arrayFree(&charArr);
    arrayFree(&stringArr);
}

void arrayPushTest(){
    Array intArr = newArray(INT);
    int i = 10;
    Object o1 = newObject(INT, &i);
    arrayPush(&intArr, o1);
    assert(*(int*)(intArr.data->ref)==10);
    assert(intArr.length == 1);
    arrayFree(&intArr);
}

void arrayPopTest(){
    Array intArr = newArray(INT);
    int i = 10;
    int j = 20;
    Object o1 = newObject(INT, &i);
    Object o2 = newObject(INT, &j);
    arrayPush(&intArr, o2);
    arrayPush(&intArr, o1);
    assert(intArr.length==2);
    arrayPop(&intArr);
    assert(intArr.length==1);
    arrayFree(&intArr);
}

void arrayInsertTest(){
    Array intArr = newArray(INT);
    int i = 10;
    int j = 20;
    Object o1 = newObject(INT, &i);
    Object o2 = newObject(INT, &j);
    arrayPush(&intArr,o1);
    arrayInsert(&intArr,5, o2);
    arrayInsert(&intArr,-5, o2);
    arrayInsert(&intArr, 0, o2);
    arrayPrint(intArr);
    assert(*(int*)(intArr.data->ref)==20);
    assert(intArr.length == 2);
    arrayFree(&intArr);
}

void arrayDeleteTest(){
    Array intArr = newArray(INT);
    int i = 10;
    int j = 20;
    Object o1 = newObject(INT, &i);
    Object o2 = newObject(INT, &j);
    arrayPush(&intArr, o2);
    arrayPush(&intArr, o1);
    arrayDelete(&intArr, 0);
    assert(*(int*)(intArr.data->ref)==10);
    assert(intArr.length == 1);
    arrayFree(&intArr);
}

void arrayExtendTest(){
    Array intArr = newArray(INT);
    int max_size = intArr.max_size;
    arrayExtend(&intArr);
    assert(intArr.max_size > max_size);
    arrayFree(&intArr);
}

void arrayShrinkTest(){
    Array intArr = newArray(INT);
    int max_size = intArr.max_size;
    arrayShrink(&intArr);
    assert(intArr.max_size < max_size);
    arrayFree(&intArr);
}
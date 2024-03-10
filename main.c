#include <stdio.h>
#include <stdlib.h>
#include "object/object.h"
#include "array/array.h"
#include "singly_linked_list/sll.h"
#include "object/tests.h"
#include "array/tests.h"
int main(){
    printf("We're creating a linked list of integers. Enter them one by one");
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
    //Unit Tests
    newObjectTest();
    ArrayTest();
    return 0;
}
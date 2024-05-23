#include <stdio.h>
#include <stdlib.h>
#include "./array/tests.h"
#include "./list/tests.h"
#include "./stack/tests.h"
#include "./queue/tests.h"
int main(){
    testArray();
    testList();
    testStack();
    testQueue();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "./linked_list/test.h "
#include "./stack/stack_test.h"
#include "./tree/tree_test.h"

int main()
{
    linkedTest();
    printf("\nEnd of linked list test\n\n");
    test_stack();
    printf("\n\nEnd of stack test\n\n");
    test_tree();
    printf("\n\nEnd of tree test\n\n");
    return 0;
}
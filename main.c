#include <stdio.h>
#include <stdlib.h>
#include "./linked_list/list_test.h"
#include "./stack/stack_test.h"
#include "./tree/tree_test.h"

int main()
{
    test_linked_list();
    printf("\nEnd of linked list test\n\n");
    test_stack();
    printf("\nEnd of stack test\n\n");
    test_tree();
    printf("\nEnd of tree test\n\n");
    return 0;
}
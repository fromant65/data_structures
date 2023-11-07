#include <stdio.h>
#include <stdlib.h>

#include "./linked_list/int/int_list_test.h"
#include "./linked_list/char/char_list_test.h"
#include "./stack/stack_test.h"
#include "./queue/queue_test.h"
#include "./tree/tree_test.h"
#include "./matrix/matrix_test.h"
#include "./hash_table/hash_table_test.h"
#include "./public_methods/test/methods_test.h"

int main()
{
    test_linked_list();
    printf("\nEnd of linked list test\n\n");
    test_char_linked_list();
    printf("\nEnd of char linked list test\n\n");
    test_stack();
    printf("\nEnd of stack test\n\n");
    test_queue();
    printf("\n\nEnd of queue test\n\n");
    test_tree();
    printf("\nEnd of tree test\n\n");
    test_matrix();
    printf("\nEnd of matrix test\n\n");
    test_hash_table();
    printf("\nEnd of hash table test\n\n");
    test_methods();
    printf("\nEnd of methods test\n\n");
    return 0;
}
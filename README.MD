# Data Structures in C

This project is about data structures. It includes three structures: IntNode, IntStack, and IntLinkedList.

## Structures:

Here's a description of the structures of the project

### IntNode:

- It represents a node for a linear structure of integers.
- It has two fields: "value" which stores an integer value, and "next" which points to another node.

### IntStack:

- It represents a stack data structure.
- It has one field: "last" which points to the last node in the stack.

### IntLinkedList:

- It represents a linked list data structure.
- It has two fields: "first" which points to the first node in the list, and "size" which stores the number of elements in the list.

## Methods

The project provides functions to perform various operations on these data structures:

For IntStack:

- `newStack()`: Creates a new stack and returns a pointer to it.
- `push()`: Adds a value to the stack.
- `pop()`: Removes the last value from the stack and returns it.
- `free_stack()`: Removes all elements from the stack and deletes it.

For IntLinkedList:

- `newList()`: Creates a new linked list and returns a pointer to it.
- `push_item()`: Adds an element to the end of the list.
- `add_item()`: Adds an element to the list at the specified index.
- `delete_item()`: Deletes an element from the list.
- `print_list()`: Prints the elements of the list.
- `free_list()`: Removes all elements from the list and deletes it.

## Compilation

You can compile the project with gcc:

`gcc -c ./main.c ./linked_list/int_list.c ./linked_list/test.c ./stack/int_stack.c ./stack/stack_test.c | gcc ./main.o ./list.o ./test.o ./int_stack.o ./stack_test.o -o main`

Or you can use the `make` command to for an easier compilation process. For this, you will need the make utility.

## Usage

After compiling, run the program with `./main`

# LinkedList Project in C

This project implements a simple linked list in C. The linked list supports basic operations such as creating a new list, adding an element to the list, deleting an element from the list, printing the list, and freeing the list.

## Files

- `list.h`: This header file contains the declarations of the `Node` and `LinkedList` structures and the functions for manipulating the linked list.
- `list.c`: This source file contains the definitions of the functions for manipulating the linked list.
- `main.c`: This source file contains the `main` function that tests the linked list functions.

## Structures

- `Node`: A node in the linked list. Each node contains an integer value and a pointer to the next node.
- `LinkedList`: A linked list. It contains a pointer to the first node and the size of the list.

## Functions

- `LinkedList *newList()`: Creates a new linked list and returns a pointer to it.
- `void push(LinkedList *l, int value)`: Adds an element to the end of the list.
- `void delete_item(LinkedList *l, int value)`: Deletes an element from the list.
- `void print_list(LinkedList *l)`: Prints the elements of the list.
- `void free_list(LinkedList *l)`: Frees the memory allocated for the list.

## Compilation

You can compile the project with `gcc`:

`gcc -c ./main.c ./linked_list/list.c ./linked_list/test.c | gcc ./main.o ./list.o ./test.o -o program`

Or you can use the `make` command to for an easier compilation process.

## Usage

After compiling the project, you can run the program with `./program`.

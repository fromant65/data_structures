# Integer Linked List Header (`list.h`)

## Description

The `list.h` header file defines the `IntLinkedList` structure and functions for creating and manipulating a simple integer-linked list. The linked list consists of integer values and provides basic operations such as insertion, deletion, and printing.

## Structure

### `IntLinkedList`

- Represents an integer-linked list.

#### Members:

- `IntNode *first`: Pointer to the first node in the list.
- `int size`: The number of elements in the list.

## Functions

### `IntLinkedList *newList()`

- Creates a new empty linked list.

#### Returns:

- `IntLinkedList*`: A pointer to the newly created linked list.

### `void push_item(IntLinkedList *l, int value)`

- Adds an element to the end of the list.

#### Parameters:

- `l`: A pointer to the linked list.
- `value`: The integer value to add to the list.

### `void add_item(IntLinkedList *l, int value, int index)`

- Adds an element to the list at the specified index.

#### Parameters:

- `l`: A pointer to the linked list.
- `value`: The integer value to add to the list.
- `index`: The index at which to insert the element.

### `void delete_item(IntLinkedList *l, int value)`

- Deletes the first occurrence of a specified element from the list.

#### Parameters:

- `l`: A pointer to the linked list.
- `value`: The integer value to be deleted from the list.

### `char *stringify_list(IntLinkedList *l)`

- Returns a string representation of the list with its items separated by blank spaces.

#### Parameters:

- `l`: A pointer to the linked list.

#### Returns:

- `char*`: A dynamically allocated string representing the list.

### `void print_list(IntLinkedList *l)`

- Prints the elements of the list to the standard output.

#### Parameters:

- `l`: A pointer to the linked list.

### `void free_list(IntLinkedList *l)`

- Frees the memory allocated for the linked list and its nodes.

#### Parameters:

- `l`: A pointer to the linked list.

## Usage

To use the `IntLinkedList` structure and functions in your C code, include this header file:

```c
#include "list.h"
```

You can then create and manipulate integer-linked lists using the provided functions. Don't forget to free the memory allocated for the list when it's no longer needed to prevent memory leaks.

## Example

Here's a simple example of creating and working with an integer-linked list:

```c
#include <stdio.h>
#include "list.h"

int main() {
    // Create a new linked list.
    IntLinkedList *list = newList();

    // Add elements to the list.
    push_item(list, 10);
    push_item(list, 20);
    push_item(list, 30);

    // Print the list.
    print_list(list);

    // Free allocated memory.
    free_list(list);

    return 0;
}
```

## Conclusion

The documentation provides an overview of the `list.h` header file, explains the structure and functions, describes usage, and includes a code example to illustrate how to use it in C programs.

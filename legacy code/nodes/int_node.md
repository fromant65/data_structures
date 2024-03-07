# Int Node Header (`int_node.h`)

## Description

The `int_node.h` header file defines the `IntNode` structure, which represents a node in an integer-linked list. It contains information about the integer value stored in the node and a pointer to the next node in the list.

## Structure

### `IntNode`

- Represents a node in an integer-linked list.

#### Members:

- `int value`: The integer value stored in the node.

- `IntNode *next`: A pointer to the next node in the linked list.

## Usage

To use the `IntNode` structure in your C code, include this header file:

```c
#include "int_node.h"
```

You can then declare and work with integer-linked list nodes in your code by creating instances of IntNode and accessing its members.

```c
IntNode* newNode = (IntNode*)malloc(sizeof(IntNode));
newNode->value = 42;
newNode->next = NULL;
```

Remember to free allocated memory when you're done with the nodes to prevent memory leaks.

## Example

```c
#include <stdio.h>
#include "int_node.h"

int main() {
    // Create two linked list nodes.
    IntNode* node1 = (IntNode*)malloc(sizeof(IntNode));
    node1->value = 10;
    node1->next = NULL;

    IntNode* node2 = (IntNode*)malloc(sizeof(IntNode));
    node2->value = 20;
    node2->next = NULL;

    // Link the nodes together.
    node1->next = node2;

    // Print the values of the linked list.
    IntNode* current = node1;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    // Free allocated memory.
    free(node1);
    free(node2);

    return 0;
}
```

This example demonstrates how to create and link IntNode instances in a simple integer-linked list.

## Conclusion

This Markdown documentation provides an overview of the `int_node.h` header file, explains the structure and its members, describes usage, and includes a code example to illustrate how to use it in C programs.

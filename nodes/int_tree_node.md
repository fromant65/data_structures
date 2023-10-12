# Integer Tree Node Header (`int_tree_node.h`)

## Description

The `int_tree_node.h` header file defines the `IntTreeNode` structure, which represents a node in a binary integer tree. Each node contains an integer value and pointers to its left and right children.

## Structure

### `IntTreeNode`

- Represents a node in a binary integer tree.

#### Members:

- `int value`: The integer value stored in the node.
- `IntTreeNode *leftChild`: Pointer to the left child node.
- `IntTreeNode *rightChild`: Pointer to the right child node.

### `newNode(int value)`

- Function to create and initialize a new `IntTreeNode` with the specified integer value.

#### Parameters:

- `value`: The integer value to be stored in the new node.

#### Returns:

- `IntTreeNode*`: A pointer to the newly created and initialized node.

## Usage

To use the `IntTreeNode` structure and the `newNode` function in your C code, include this header file:

```c
#include "int_tree_node.h"
```

You can then declare and work with binary tree nodes in your code by creating instances of IntTreeNode and using the newNode function to initialize them.

```c
// Create a new node with a value of 42.
IntTreeNode* newNode = newNode(42);
```

Don't forget to manage memory by freeing nodes when they are no longer needed to prevent memory leaks.

## Example

Here's a simple example of creating a binary tree structure and using the newNode function to create nodes:

```c
#include <stdio.h>
#include "int_tree_node.h"

int main() {
    // Create a binary tree with a root node.
    IntTreeNode* root = newNode(10);
    root->leftChild = newNode(5);
    root->rightChild = newNode(20);

    // Print the values of the tree.
    printf("Root: %d\n", root->value);
    printf("Left Child: %d\n", root->leftChild->value);
    printf("Right Child: %d\n", root->rightChild->value);

    // Free allocated memory.
    free(root->leftChild);
    free(root->rightChild);
    free(root);

    return 0;
}
```

This example demonstrates how to create a binary tree structure and use the newNode function to create and initialize tree nodes.

## Conclusion

The documentation provides an overview of the `int_tree_node.h` header file, explains the structure and function, describes usage, and includes a code example to illustrate how to use it in C programs.

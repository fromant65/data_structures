# Binary Search Tree Header (`tree.h`)

## Description

The `tree.h` header file defines the `BinarySearchTree` structure and functions for creating and manipulating a binary search tree (BST). A binary search tree is a data structure that stores values in a hierarchical manner, allowing for efficient search, insertion, and deletion of elements. The `BinarySearchTree` structure consists of integer values and provides operations for tree creation, manipulation, and traversal.

## Structure

### `BinarySearchTree`

- Represents a binary search tree.

#### Members:

- `IntTreeNode *head`: Pointer to the root node of the tree.
- `int size`: The number of elements in the tree.

## Functions

### `BinarySearchTree *newTree()`

- Creates a new empty binary search tree.

#### Returns:

- `BinarySearchTree*`: A pointer to the newly created tree.

### `BinarySearchTree *listToTree(int values[], int size)`

- Converts an array of integer values into a binary search tree.

#### Parameters:

- `values`: An array of integer values to be inserted into the tree.
- `size`: The number of elements in the array.

#### Returns:

- `BinarySearchTree*`: A pointer to the newly created tree.

### `void addElement(BinarySearchTree *tree, int value)`

- Inserts a new element with the specified value into the binary search tree.

#### Parameters:

- `tree`: A pointer to the binary search tree.
- `value`: The integer value to add to the tree.

### `int searchElement(BinarySearchTree *tree, int value)`

- Searches for an element with the specified value in the binary search tree.

#### Parameters:

- `tree`: A pointer to the binary search tree.
- `value`: The integer value to search for.

#### Returns:

- `int`: Returns 1 if the value is found in the tree, and 0 if it's not found.

### `void deleteElement(BinarySearchTree *tree, int value)`

- Deletes an element with the specified value from the binary search tree.

#### Parameters:

- `tree`: A pointer to the binary search tree.
- `value`: The integer value to delete from the tree.

### `void freeTree(BinarySearchTree *tree)`

- Frees the memory allocated for the binary search tree and its nodes.

#### Parameters:

- `tree`: A pointer to the binary search tree.

### `IntTreeNode *minValueNode(IntTreeNode *node)`

- Finds the node with the minimum value in the binary search tree.

#### Parameters:

- `node`: The root node of the tree or a subtree.

#### Returns:

- `IntTreeNode*`: A pointer to the node with the minimum value.

### `IntTreeNode *maxValueNode(IntTreeNode *node)`

- Finds the node with the maximum value in the binary search tree.

#### Parameters:

- `node`: The root node of the tree or a subtree.

#### Returns:

- `IntTreeNode*`: A pointer to the node with the maximum value.

### `char *stringify_tree(BinarySearchTree *t, char method[])`

- Returns a string representation of the binary search tree.

#### Parameters:

- `t`: A pointer to the binary search tree.
- `method[]`: The traversal method (e.g., "inorder," "preorder," "postorder").

#### Returns:

- `char*`: A dynamically allocated string representing the tree.

## Usage

To use the `BinarySearchTree` structure and functions in your C code, include this header file:

```c
#include "tree.h"
```

You can then create and manipulate binary search trees using the provided functions. Ensure that you free the memory allocated for the tree when it's no longer needed to prevent memory leaks.

## Example

Here's a simple example of creating a binary search tree, inserting elements, searching for values, and printing the tree:

```c
#include <stdio.h>
#include "tree.h"

int main() {
    // Create a new binary search tree.
    BinarySearchTree *tree = newTree();

    // Insert elements into the tree.
    addElement(tree, 10);
    addElement(tree, 20);
    addElement(tree, 5);
    addElement(tree, 30);

    // Search for a value in the tree.
    int valueToSearch = 20;
    int found = searchElement(tree, valueToSearch);
    printf("Value %d found: %s\n", valueToSearch, found ? "Yes" : "No");

    // Print the tree using the "inorder" traversal.
    char method[] = "inorder";
    char *treeString = stringify_tree(tree, method);
    printf("Binary Search Tree (%s): %s\n", method, treeString);

    // Free allocated memory.
    freeTree(tree);
    free(treeString);

    return 0;
}
```

This example demonstrates how to create a binary search tree, insert elements, search for values, and print the tree using the provided functions.

## Conclusion

The documentation provides an overview of the `tree.h` header file, explains the structure and functions, describes usage, and includes a code example to illustrate how to use it in C programs.

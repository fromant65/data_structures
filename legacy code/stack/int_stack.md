# Integer Stack Header (`stack.h`)

## Description

The `stack.h` header file defines the `IntStack` structure and functions for creating and manipulating a simple integer stack. A stack is a data structure that follows the Last-In-First-Out (LIFO) principle, where elements are added and removed from the top. The `IntStack` structure consists of integer values and provides basic operations such as insertion, removal, and memory management.

## Structure

### `IntStack`

- Represents an integer stack.

#### Members:

- `struct IntNode *last`: Pointer to the last (top) node in the stack.

## Functions

### `IntStack *newStack()`

- Creates a new empty stack.

#### Returns:

- `IntStack*`: A pointer to the newly created stack.

### `void push(IntStack *stack, int value)`

- Adds a new value to the top of the stack.

#### Parameters:

- `stack`: A pointer to the stack.
- `value`: The integer value to add to the stack.

### `int pop(IntStack *stack)`

- Removes the last (top) value from the stack and returns it.

#### Parameters:

- `stack`: A pointer to the stack.

#### Returns:

- `int`: The removed integer value.

### `void free_stack(IntStack *stack)`

- Removes all elements from the stack and deletes the stack.

#### Parameters:

- `stack`: A pointer to the stack.

## Usage

To use the `IntStack` structure and functions in your C code, include this header file:

```c
#include "stack.h"
```

You can then create and manipulate integer stacks using the provided functions. Don't forget to free the memory allocated for the stack when it's no longer needed to prevent memory leaks.

## Example

Here's a simple example of creating and working with an integer stack:

```c
#include <stdio.h>
#include "stack.h"

int main() {
// Create a new stack.
IntStack \*stack = newStack();

    // Push elements onto the stack.
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    // Pop and print elements from the stack.
    while (stack->last != NULL) {
        int value = pop(stack);
        printf("%d ", value);
    }

    // Free allocated memory.
    free_stack(stack);

    return 0;

}
```

This example demonstrates how to create a stack, push elements, pop elements, and print the values using the provided functions.

## Conclusion

The documentation provides an overview of the `stack.h` header file, explains the structure and functions, describes usage, and includes a code example to illustrate how to use it in C programs.

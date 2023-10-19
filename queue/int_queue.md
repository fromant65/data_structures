# Integer Queue Header (`int_queue.h`)

## Description

The `int_queue.h` header file defines the `IntQueue` structure and functions for creating and manipulating a simple integer queue. A queue is a data structure that follows the First-In-First-Out (FIFO) principle, where elements are added at the back and removed from the front. The `IntQueue` structure consists of integer values and provides basic operations such as insertion, deletion, and printing.

## Structure

### `IntQueue`

- Represents an integer queue.

#### Members:

- `struct IntNode *first`: Pointer to the first (front) node in the queue.
- `struct IntNode *last`: Pointer to the last (back) node in the queue.
- `int size`: The number of elements in the queue.

## Functions

### `IntQueue *newQueue()`

- Creates a new empty queue.

#### Returns:

- `IntQueue*`: A pointer to the newly created queue.

### `void queue_push_item(IntQueue *q, int value)`

- Adds a new element to the back of the queue.

#### Parameters:

- `q`: A pointer to the queue.
- `value`: The integer value to add to the queue.

### `void queue_delete_item(IntQueue *q)`

- Deletes the first (front) element from the queue.

#### Parameters:

- `q`: A pointer to the queue.

### `int *queue_to_array(IntQueue *q)`

- Converts the queue elements into an integer array.

#### Parameters:

- `q`: A pointer to the queue.

#### Returns:

- `int*`: A dynamically allocated integer array containing the elements of the queue.

### `char *stringify_queue(IntQueue *q)`

- Returns a string representation of the queue values separated by blank spaces.

#### Parameters:

- `q`: A pointer to the queue.

#### Returns:

- `char*`: A dynamically allocated string containing the queue values separated by blank spaces.

### `print_queue(IntQueue *q)`

- Prints the elements of the queue to the standard output.

#### Parameters:

- `q`: A pointer to the queue.

### `void free_queue(IntQueue *q)`

- Frees the memory allocated for the queue and its nodes.

#### Parameters:

- `q`: A pointer to the queue.

## Usage

To use the `IntQueue` structure and functions in your C code, include this header file:

```c
#include "int_queue.h"
```

You can then create and manipulate integer queues using the provided functions. Remember to free the memory allocated for the queue when it's no longer needed to prevent memory leaks.

## Example

Here's a simple example of creating and working with an integer queue:

```c
#include <stdio.h>
#include "int_queue.h"

int main() {
    // Create a new queue.
    IntQueue *queue = newQueue();

    // Add elements to the queue.
    queue_push_item(queue, 10);
    queue_push_item(queue, 20);
    queue_push_item(queue, 30);

    // Print the queue.
    print_queue(queue);

    // Convert the queue to an array.
    int *queueArray = queue_to_array(queue);

    // Print the array.
    printf("Queue Elements as an Array: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queueArray[i]);
    }
    printf("\n");

    // Free allocated memory.
    free(queueArray);
    free_queue(queue);

    return 0;
}
```

This example demonstrates how to create a queue, add elements, convert the queue to an array, and print both the queue and the array using the provided functions.

## Conclusion

The documentation provides an overview of the int_queue.h header file, explains the structure and functions, describes usage, and includes a code example to illustrate how to use it in C programs.

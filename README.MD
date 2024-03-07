# C Data Structures Project

## Main folder
This folder includes various generic data structures implemented in C. 

## Legacy Code Folder
This folder includes various type specific data structures implemented in C, each with its own dedicated header file and individual documentation. The available data structures are as follows:

1. `int_node`: Simple nodes with an optional child node.

   - Header File: [int_node.h]
   - Documentation: [int_node.md]

2. `int_tree_node`: Binary tree nodes used in binary search trees.

   - Header File: [int_tree_node.h]
   - Documentation: [int_tree_node.md]

3. `stack`: A Last-In-First-Out (LIFO) stack for managing integer values.

   - Header File: [stack.h]
   - Documentation: [stack.md]

4. `queue`: A First-In-First-Out (FIFO) queue for managing integer values.

   - Header File: [int_queue.h]
   - Documentation: [queue.md]

5. `linked_list`: A linked list structure for managing integer values.

   - Header File: [list.h]
   - Documentation: [list.md]

6. `tree`: A binary search tree structure for managing integer values.
   - Header File: [tree.h]
   - Documentation: [tree.md]

7. `matrix`: A data structure for managing matrices.

   - Header File: [matrix.h]
   - Documentation: [matrix.md]

## Prerequisites

Before compiling and running the project, make sure you have the following prerequisites:

- A C compiler (e.g., GCC)
- Make utility (for using the provided makefile)

## How to Compile and Run

To compile and run the project, a `makefile` is provided in the repository. Please follow these steps:

1. Open a terminal or command prompt.

2. Navigate to the project directory.

3. To compile the project, execute the following command:

```shell
   make
```

This command will build the project using the makefile.

4. Once the project is successfully compiled, you can run it by executing:

```shell
   ./main
```

The makefile creates an executable named main by default.

You can explore and test the data structures and their functionalities by running the main executable.

Remember to refer to the individual documentation files linked above for more details on each data structure and how to use them effectively.

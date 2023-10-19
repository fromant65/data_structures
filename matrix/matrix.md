# Matrix Header (`matrix.h`)

## Description

The `matrix.h` header file defines the `Matrix` structure and functions for working with matrices. A matrix is a two-dimensional array of numbers often used in various mathematical and scientific applications. This header provides functions for creating, manipulating, and performing operations on matrices.

## Structure

### `Matrix`

- Represents a two-dimensional matrix.

#### Members:

- `int m`: The number of rows in the matrix.
- `int n`: The number of columns in the matrix.
- `double **matrix`: A double pointer to a 2D array containing matrix elements.

### `newMatrix(int m, int n, double **matrix)`

- Function to create a new matrix with the specified dimensions and matrix data.

#### Parameters:

- `m`: The number of rows in the matrix.
- `n`: The number of columns in the matrix.
- `matrix`: A double pointer to a 2D array containing the matrix data.

#### Returns:

- `Matrix*`: A pointer to the newly created matrix.

### `createMatrix(int m, int n, double arr[m][n])`

- Function to create a new matrix from a 2D array.

#### Parameters:

- `m`: The number of rows in the matrix.
- `n`: The number of columns in the matrix.
- `arr[m][n]`: A 2D array containing the matrix data.

#### Returns:

- `double**`: A double pointer to the dynamically allocated 2D array representing the matrix.

### `freeMatrix(Matrix *matrix)`

- Function to free the memory allocated for a matrix and delete it.

#### Parameters:

- `matrix`: A pointer to the matrix to be freed.

### `is_matrix_square(Matrix *matrix)`

- Function to check if a matrix is square (i.e., the number of rows equals the number of columns).

#### Parameters:

- `matrix`: A pointer to the matrix.

#### Returns:

- `int`: Returns 1 if the matrix is square, otherwise 0.

### `matrix_sum(Matrix *m1, Matrix *m2)`

- Function to calculate the sum of two matrices.

#### Parameters:

- `m1`: A pointer to the first matrix.
- `m2`: A pointer to the second matrix.

#### Returns:

- `Matrix*`: A pointer to the result matrix containing the sum of `m1` and `m2`. Returns `NULL` if the matrices are of different sizes.

### `matrix_escalar_mult(Matrix *matrix, double n)`

- Function to multiply a matrix by a scalar value.

#### Parameters:

- `matrix`: A pointer to the matrix.
- `n`: The scalar value to multiply with the matrix.

#### Returns:

- `Matrix*`: A pointer to the result matrix.

### `matrix_mult(Matrix *m1, Matrix *m2)`

- Function to calculate the matrix product of two matrices.

#### Parameters:

- `m1`: A pointer to the first matrix.
- `m2`: A pointer to the second matrix.

#### Returns:

- `Matrix*`: A pointer to the result matrix containing the product of `m1` and `m2`. Returns `NULL` if the matrices cannot be multiplied.

### `triangular_matrix(Matrix *matrix)`

- Function to transform a matrix into an equivalent upper triangular matrix.

#### Parameters:

- `matrix`: A pointer to the matrix.

#### Returns:

- `Matrix*`: A pointer to the equivalent upper triangular matrix. Returns `NULL` if the matrix is not square.

### `matrix_det(Matrix *matrix)`

- Function to calculate the determinant of a square matrix.

#### Parameters:

- `matrix`: A pointer to the square matrix.

#### Returns:

- `double`: The determinant of the matrix if it is square. Exits if the matrix is not square.

### `inverse_matrix(Matrix *matrix)`

- Function to calculate the inverse of a square matrix.

#### Parameters:

- `matrix`: A pointer to the square matrix.

#### Returns:

- `Matrix*`: A pointer to the inverse of the matrix if it exists. Returns `NULL` otherwise.

### `null_matrix(int m, int n)`

- Function to create a matrix filled with zeros of a specified size.

#### Parameters:

- `m`: The number of rows in the matrix.
- `n`: The number of columns in the matrix.

#### Returns:

- `Matrix*`: A pointer to the newly created zero-filled matrix.

### `identity_matrix(int m)`

- Function to create an identity matrix of a specified size.

#### Parameters:

- `m`: The size of the square identity matrix.

#### Returns:

- `Matrix*`: A pointer to the newly created identity matrix.

### `print_matrix(Matrix *m)`

- Function to print the elements of a matrix.

#### Parameters:

- `m`: A pointer to the matrix.

## Usage

To use the `Matrix` structure and functions in your C code, include this header file:

```c
#include "matrix.h"
```

You can then create, manipulate, and perform various operations on matrices using the provided functions.

## Example

Here's a simple use example of the Matrix data structure and some of its functions:

```c
#include <stdio.h>
#include "matrix.h"

int main() {
    // Create a 2x2 matrix with predefined values.
    double initialData[2][2] = {{1.0, 2.0}, {3.0, 4.0}};
    Matrix *matrixA = createMatrix(2, 2, initialData);

    // Print the original matrix.
    printf("Original Matrix A:\n");
    print_matrix(matrixA);

    // Check if the matrix is square.
    int isSquare = is_matrix_square(matrixA);
    printf("Matrix A is square: %s\n", isSquare ? "Yes" : "No");

    // Calculate the determinant of the matrix.
    double detA = matrix_det(matrixA);
    printf("Determinant of Matrix A: %lf\n", detA);

    // Create an identity matrix of the same size.
    Matrix *identityA = identity_matrix(2);
    printf("Identity Matrix of Size 2:\n");
    print_matrix(identityA);

    // Calculate the product of the original matrix and the identity matrix.
    Matrix *product = matrix_mult(matrixA, identityA);
    printf("Product of Matrix A and Identity Matrix:\n");
    print_matrix(product);

    // Free allocated memory.
    freeMatrix(matrixA);
    freeMatrix(identityA);
    freeMatrix(product);

    return 0;
}
```

This example demonstrates how to create, manipulate, and perform operations on matrices using the provided functions in the `matrix.h` header.

## Conclusion

The documentation provides an overview of the matrix.h header file, explains the structure and functions for working with matrices, describes usage, and includes code examples to illustrate how to work with matrices in C programs.

#ifndef MATRIX_H
#define MATRIX_H

typedef struct
{
    int m, n;
    double **matrix;
} Matrix;

Matrix *newMatrix(int m, int n, double **matrix);      // Returns a pointer to a Matrix struct
double **createMatrix(int m, int n, double arr[m][n]); // Returns a double pointer to double from a double 2d matrix
void freeMatrix(Matrix *matrix);                       // frees the memory of the matrix and deletes it
int is_matrix_square(Matrix *matrix);                  // returns 1 if matrix->m == matrix->n, otherwise 0
Matrix *matrix_sum(Matrix *m1, Matrix *m2);            // returns the matrix sum or NULL if matrices are of different size
Matrix *matrix_escalar_mult(Matrix *matrix, double n); // returns the product of the matrix by an scalar value
Matrix *matrix_mult(Matrix *m1, Matrix *m2);           // returns the matrix multiplication or NULL if matrices cannot be multiplied
Matrix *triangular_matrix(Matrix *matrix);             // returns an equivalent triangular matrix, or NULL if the matrix is not square
double matrix_det(Matrix *matrix);                     // returns the determinant of the matrix if it is square, exits otherwise
Matrix *inverse_matrix(Matrix *matrix);                // returns the inverse of the matrix if it exists, NULL otherwise
Matrix *null_matrix(int m, int n);                     // returns a matrix full of zeros of size m * n
Matrix *identity_matrix(int m);                        // returns an identity matrix of size m
Matrix *erfMatrix(Matrix *matrix);                     // returns the correspondant row echelon form matrix
void print_matrix(Matrix *m);                          // prints matrix
#endif

#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

Matrix *newMatrix(int m, int n, double **values)
{
    Matrix *matrix = malloc(sizeof(Matrix));
    if (matrix == NULL)
    {
        printf("Matrix couldn't be created.\n");
        exit(1);
    }
    matrix->m = m;
    matrix->n = n;
    matrix->matrix = values;
    return matrix;
}

double **createMatrix(int m, int n, double arr[m][n])
{
    double **matrix = malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++)
    {
        matrix[i] = malloc(n * sizeof(double));
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = arr[i][j];
        }
    }
    return matrix;
}

void freeMatrix(Matrix *matrix)
{
    for (int i = 0; i < matrix->m; i++)
    {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

int is_matrix_square(Matrix *matrix)
{
    return (matrix->m == matrix->n);
}

Matrix *matrix_sum(Matrix *m1, Matrix *m2)
{
    if (m1->m != m2->m || m1->n != m2->n)
    {
        return NULL;
    }
    double **sum = malloc(sizeof(double *) * m1->m);
    for (int i = 0; i < m1->m; i++)
    {
        double *column = malloc(sizeof(double) * m1->n);
        for (int j = 0; j < m1->n; j++)
        {
            column[j] = m1->matrix[i][j] + m2->matrix[i][j];
        }
        sum[i] = column;
    }
    Matrix *result = newMatrix(m1->m, m1->n, sum);
    return result;
}

Matrix *matrix_escalar_mult(Matrix *matrix, double n)
{
    double **rows = malloc(sizeof(double *) * matrix->m);

    for (int i = 0; i < matrix->m; i++)
    {
        double *column = malloc(sizeof(double) * matrix->n);
        for (int j = 0; j < matrix->n; j++)
        {
            column[j] = matrix->matrix[i][j] * n;
        }
        rows[i] = column;
    }
    Matrix *result = newMatrix(matrix->m, matrix->n, rows);
    return result;
}

Matrix *matrix_mult(Matrix *m1, Matrix *m2)
{
}
float matrix_det(Matrix *matrix) {}
Matrix *inverse_matrix(Matrix *matrix)
{
}
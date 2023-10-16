#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include <math.h>

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
    if (m1->n != m2->m)
    {
        printf("Multiplication can't be done between matrices.\n");
        return NULL;
    }
    double result[m1->m][m2->n];
    for (int i = 0; i < m1->m; i++)
    {
        for (int j = 0; j < m2->n; j++)
        {
            double sum = 0;
            for (int k = 0; k < m1->n; k++)
            {
                sum += m1->matrix[i][k] * m2->matrix[k][j];
            }
            result[i][j] = sum;
        }
    }
    double **result_p = createMatrix(m1->m, m2->n, result);
    Matrix *product_matrix = newMatrix(m1->m, m2->n, result_p);
    return product_matrix;
}

Matrix *triangular_matrix(Matrix *matrix)
{
    int m = matrix->m;
    int n = matrix->n;
    double **mat = matrix->matrix;

    if (m != n)
    {
        printf("The matrix is not square!\n");
        return NULL;
    }

    double **result = (double **)malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++)
    {
        result[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++)
        {
            result[i][j] = mat[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (result[i][i] == 0)
        {
            // Find a row below with non-zero pivot element
            int swap_row = -1;
            for (int j = i + 1; j < m; j++)
            {
                if (result[j][i] != 0)
                {
                    swap_row = j;
                    break;
                }
            }

            if (swap_row == -1)
            {
                printf("The matrix is singular!\n");
                freeMatrix(newMatrix(m, n, result));
                return null_matrix(m, n);
            }

            // Swap rows
            double *temp = result[i];
            result[i] = result[swap_row];
            result[swap_row] = temp;
        }

        for (int j = i + 1; j < m; j++)
        {
            double factor = result[j][i] / result[i][i];
            for (int k = 0; k < n; k++)
            {
                result[j][k] -= factor * result[i][k];
            }
        }
    }

    return newMatrix(m, n, result);
}

double matrix_det(Matrix *matrix)
{
    int m = matrix->m;
    double **mat = matrix->matrix;

    if (m != matrix->n)
    {
        printf("The matrix is not square!\n");
        exit(1);
    }

    if (m == 1)
    {
        return mat[0][0];
    }
    else if (m == 2)
    {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }
    else
    {
        double det = 1;
        Matrix *triangular = triangular_matrix(matrix);
        for (int i = 0; i < m; i++)
        {
            det *= triangular->matrix[i][i];
        }
        freeMatrix(triangular);
        return det;
    }
}
Matrix *inverse_matrix(Matrix *matrix)
{
    int m = matrix->m;
    double **mat = matrix->matrix;

    if (m != matrix->n)
    {
        printf("The matrix is not square!\n");
        return NULL;
    }

    Matrix *augmented = (Matrix *)malloc(sizeof(Matrix));
    augmented->m = m;
    augmented->n = 2 * m;
    augmented->matrix = (double **)malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++)
    {
        augmented->matrix[i] = (double *)malloc(2 * m * sizeof(double));
        for (int j = 0; j < m; j++)
        {
            augmented->matrix[i][j] = mat[i][j];
        }
        for (int j = m; j < 2 * m; j++)
        {
            augmented->matrix[i][j] = (i == (j - m)) ? 1 : 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        double pivot = augmented->matrix[i][i];
        if (pivot == 0)
        {
            // Find a row below with non-zero pivot element
            int swap_row = -1;
            for (int j = i + 1; j < m; j++)
            {
                if (augmented->matrix[j][i] != 0)
                {
                    swap_row = j;
                    break;
                }
            }

            if (swap_row == -1)
            {
                printf("The matrix is not invertible!\n");
                freeMatrix(augmented);
                return NULL;
            }

            // Swap rows
            double *temp = augmented->matrix[i];
            augmented->matrix[i] = augmented->matrix[swap_row];
            augmented->matrix[swap_row] = temp;

            pivot = augmented->matrix[i][i];
        }

        for (int j = 0; j < 2 * m; j++)
        {
            augmented->matrix[i][j] /= pivot;
        }
        for (int j = 0; j < m; j++)
        {
            if (j != i)
            {
                double factor = augmented->matrix[j][i];
                for (int k = 0; k < 2 * m; k++)
                {
                    augmented->matrix[j][k] -= factor * augmented->matrix[i][k];
                }
            }
        }
    }

    Matrix *inverse = (Matrix *)malloc(sizeof(Matrix));
    inverse->m = m;
    inverse->n = m;
    inverse->matrix = (double **)malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++)
    {
        inverse->matrix[i] = (double *)malloc(m * sizeof(double));
        for (int j = 0; j < m; j++)
        {
            inverse->matrix[i][j] = augmented->matrix[i][j + m];
        }
    }

    freeMatrix(augmented);
    return inverse;
}

Matrix *null_matrix(int m, int n)
{
    double **rows = malloc(sizeof(double *) * m);
    for (int i = 0; i < m; i++)
    {
        double *column = malloc(sizeof(double) * n);
        for (int j = 0; j < n; j++)
        {
            column[j] = 0;
        }
        rows[i] = column;
    }
    Matrix *matrix = newMatrix(m, n, rows);
    return matrix;
}

Matrix *identity_matrix(int m)
{
    double **rows = malloc(sizeof(double **) * m);
    for (int i = 0; i < m; i++)
    {
        double *column = malloc(sizeof(double) * m);
        for (int j = 0; j < m; j++)
        {
            if (i == j)
            {
                column[j] = 1;
            }
            else
            {
                column[j] = 0;
            }
        }
        rows[i] = column;
    }
    Matrix *result = newMatrix(m, m, rows);
    return result;
}

void print_matrix(Matrix *m)
{
    for (int i = 0; i < m->m; i++)
    {
        for (int j = 0; j < m->n; j++)
        {
            printf("%.2f ", m->matrix[i][j]);
        }
        printf("\n");
    }
}
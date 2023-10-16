#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "matrix_test.h"

void test_newMatrix();
void test_is_matrix_square();
void test_matrix_sum();
void test_matrix_escalar_mult();
void test_matrix_mult();
void test_matrix_det();
void test_inverse_matrix();

void test_matrix()
{
    printf("Testing newMatrix...\n");
    test_newMatrix();
    printf("Testing is_matrix_square...\n");
    test_is_matrix_square();
    printf("Testing matrix_sum...\n");
    test_matrix_sum();
    printf("Testing escalar_mult...\n");
    test_matrix_escalar_mult();
    printf("Testing matrix_mult...\n");
    test_matrix_mult();
    printf("Testing matrix_det...\n");
    test_matrix_det();
    printf("Testing inverse_matrix...\n");
    test_inverse_matrix();
}

void test_newMatrix()
{
    double **values = malloc(sizeof(double *) * 2);
    for (int i = 0; i < 2; i++)
    {
        values[i] = malloc(sizeof(double) * 2);
        for (int j = 0; j < 2; j++)
        {
            values[i][j] = i + j;
        }
    }
    Matrix *m = newMatrix(2, 2, values);
    assert(m != NULL);
    assert(m->m == 2);
    assert(m->n == 2);
    assert(m->matrix == values);
    freeMatrix(m);
}

void test_is_matrix_square()
{
    double **v1 = malloc(sizeof(double *) * 2);
    for (int i = 0; i < 2; i++)
    {
        v1[i] = malloc(sizeof(double) * 2);
        for (int j = 0; j < 2; j++)
        {
            v1[i][j] = i + j;
        }
    }
    Matrix *m1 = newMatrix(2, 2, v1);
    assert(is_matrix_square(m1) == 1);
    freeMatrix(m1);
    double **v2 = malloc(sizeof(double *) * 2);
    for (int i = 0; i < 2; i++)
    {
        v2[i] = malloc(sizeof(double) * 3);
        for (int j = 0; j < 2; j++)
        {
            v2[i][j] = i + j;
        }
    }
    Matrix *m2 = newMatrix(2, 3, v2);
    assert(is_matrix_square(m2) == 0);
    freeMatrix(m2);
}

void test_matrix_sum()
{
    double m_v_1[2][3] = {
        {10, 11, 12},
        {13, 14, 15}};
    double m_v_2[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};
    double sum_v[2][3] = {
        {11, 13, 15},
        {17, 19, 21}};
    double **m1 = createMatrix(2, 3, m_v_1);
    double **m2 = createMatrix(2, 3, m_v_2);
    Matrix *matrix1 = newMatrix(2, 3, m1);
    Matrix *matrix2 = newMatrix(2, 3, m2);
    Matrix *sum = matrix_sum(matrix1, matrix2);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            assert(sum->matrix[i][j] == sum_v[i][j]);
        }
    }
    freeMatrix(matrix1);
    freeMatrix(matrix2);
    freeMatrix(sum);
}

void test_matrix_escalar_mult()
{
    int n = 2;
    double m_v[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    double result[3][3] = {
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}};
    double **m_pp = createMatrix(3, 3, m_v);
    Matrix *matrix = newMatrix(3, 3, m_pp);
    Matrix *prod = matrix_escalar_mult(matrix, n);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            assert(prod->matrix[i][j] == result[i][j]);
        }
    }
    free(matrix);
    free(prod);
}

void test_matrix_mult()
{
    // You need to implement this test based on your matrix_mult function
}

void test_matrix_det()
{
    // You need to implement this test based on your matrix_det function
}

void test_inverse_matrix()
{
    // You need to implement this test based on your inverse_matrix function
}

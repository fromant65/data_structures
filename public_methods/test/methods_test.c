#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "methods_test.h"
#include "../msort.h"
int comp_char(const void *c1, const void *c2);
int comp_int(const void *a, const void *b);
void test_msort();

void test_methods()
{
    printf("Testing msort...\n");
    test_msort();
    printf("All tests finished successfully\n");
}

int comp_char(const void *c1, const void *c2)
{
    return strcmp((char *)c1, (char *)c2) == -1;
}

int comp_int(const void *a, const void *b)
{
    return *(int *)a < *(int *)b;
}

void test_msort()
{

    char str[8] = "Manuela";
    void *pstr = &str;
    char *newstr = (char *)msort(pstr, strlen(str), sizeof(char), comp_char);
    assert(!strcmp(newstr, "Maaelnu"));
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *s_arr = msort(arr, 10, sizeof(int), comp_int);
    for (int i = 0; i < 10; i++)
    {
        assert(s_arr[i] == i + 1);
    }
}
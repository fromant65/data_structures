#include <stdlib.h>
#include "msort.h"
#include <string.h>
#include <stdio.h>
void *merge(void *l1, void *l2, size_t l1_size, size_t l2_size, size_t t_size, int (*comp)(const void *v1, const void *v2));

void *msort(void *list, size_t l_size, size_t t_size, int (*comp)(const void *v1, const void *v2))
{
    if (l_size <= 1)
        return list;
    int half = l_size / 2;
    void *left = msort(list, half, t_size, comp);
    void *right = msort(list + half * t_size, l_size - half, t_size, comp);
    return merge(left, right, half, l_size - half, t_size, comp);
}

void *merge(void *l1, void *l2, size_t l1_size, size_t l2_size, size_t t_size, int (*comp)(const void *v1, const void *v2))
{
    int i = 0, j = 0, k = 0;
    void *merged = malloc(t_size * (l1_size + l2_size));
    while (i < l1_size && j < l2_size)
    {
        void *v1 = l1 + t_size * i, *v2 = l2 + t_size * j;
        if (comp(v1, v2))
        {
            memcpy((void *)(merged + k * t_size), (void *)v1, t_size);
            i++;
            k++;
        }
        else
        {
            memcpy((void *)(merged + k * t_size), (void *)v2, t_size);
            j++;
            k++;
        }
    }
    int l1_index = i * t_size;
    int l2_index = j * t_size;
    int m_index = k * t_size;
    if (i < l1_size)
    {
        memcpy(merged + m_index, l1 + l1_index, t_size * (l1_size - i));
    }
    if (j < l2_size)
    {
        memcpy(merged + m_index, l2 + l2_index, t_size * (l2_size - j));
    }
    free(l1);
    free(l2);
    return merged;
}
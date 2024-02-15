#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "msort.h"

void *merge(void *left, void *right, size_t left_size, size_t right_size, size_t t_size, int (*comp)(const void *v1, const void *v2));

void *msort(void *list, size_t l_size, size_t t_size, int (*comp)(const void *v1, const void *v2))
{
    if (l_size <= 1)
        return list;
    int half = l_size / 2;
    void *left = msort(list, half, t_size, comp);
    void *right = msort(list + half * t_size, l_size - half, t_size, comp);
    return merge(left, right, half, l_size - half, t_size, comp);
}

//Produces memory leaks and errors when writing strings
void *merge(void *left, void *right, size_t left_size, size_t right_size, size_t t_size, int (*comp)(const void *v1, const void *v2)) {
    void *merged = malloc(t_size * (left_size + right_size));
    if (!merged) {
        return NULL;
    }
    //Merging the lists
    int i =  0, j =  0, k =  0;
    while (i < left_size && j < right_size) {
        if (comp(left + i * t_size, right + j * t_size) !=0) {
            memcpy(merged + k * t_size, left + i * t_size, t_size);
            i++;
        } else {
            memcpy(merged + k * t_size, right + j * t_size, t_size);
            j++;
        }
        k++;
    }

    //Writing what's left on each list after merging
    while (i < left_size) {
        memcpy(merged + k * t_size, left + i * t_size, t_size);
        i++;
        k++;
    }

    while (j < right_size) {
        memcpy(merged + k * t_size, right + j * t_size, t_size);
        j++;
        k++;
    }

    return merged;
}

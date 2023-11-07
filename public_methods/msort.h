#ifndef MSORT
#define MSORT
#include <stdlib.h>

void *msort(void *list, size_t l_size, size_t t_size, int (*comp)(const void *v1, const void *v2));

#endif
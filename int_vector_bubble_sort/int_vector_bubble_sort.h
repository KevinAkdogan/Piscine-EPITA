#ifndef INT_VECTOR_BUBBLE_SORT_H
#define INT_VECTOR_BUBBLE_SORT_H

#define INT_VECTOR_LENGTH 64

#include <stddef.h>

struct int_vector
{
    size_t size;
    int data[INT_VECTOR_LENGTH];
};

static struct int_vector swap(struct int_vector vec, size_t i, size_t j);
struct int_vector int_vector_bubble_sort(struct int_vector vec);

#endif

#ifndef INT_VECTOR_INSERT_SORT_H
#define INT_VECTOR_INSERT_SORT_H

#define INT_VECTOR_LENGTH 64

#include <stddef.h>

struct int_vector
{
    size_t size;
    int data[INT_VECTOR_LENGTH];
};

static struct int_vector swap(struct int_vector vec, size_t a, size_t b);
struct int_vector int_vector_insert_sort(struct int_vector vec);

#endif /* !INT_VECTOR_INSERT_SORT_H */

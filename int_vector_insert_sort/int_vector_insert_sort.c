#include "int_vector_insert_sort.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

static struct int_vector swap(struct int_vector vec, size_t a, size_t b)
{
    int tmp = vec.data[a];
    vec.data[a] = vec.data[b];
    vec.data[b] = tmp;
    return vec;
}

struct int_vector int_vector_insert_sort(struct int_vector vec)
{
    if (vec.size > 0)
    {
        for (size_t i = 0; i < vec.size; i++)
        {
            size_t j = i;

            while (vec.data[j - 1] > vec.data[j] && j > 0)
            {
                vec = swap(vec, j - 1, j);
                j -= 1;
            }
        }
    }
    return vec;
}

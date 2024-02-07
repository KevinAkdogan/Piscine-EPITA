#include "int_vector_hill.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int hill_max(const struct int_vector vec)
{
    int i = 0;
    for (size_t j = 0; j < vec.size; j++)
    {
        if (vec.data[j] > vec.data[i])
        {
            i = j;
        }
    }
    return i;
}

int int_vector_hill(struct int_vector vec)
{
    if (vec.size <= 0)
        return -1;

    else if (vec.size == 1)
        return 0;

    int x = 0;
    size_t i = 0;

    while (vec.data[i] <= vec.data[i + 1])
    {
        if (i + 1 == vec.size)
        {
            x = vec.size;
        }
        else
        {
            x = i + 1;
        }
        if (vec.data[i] < 0 || vec.data[i + 1] < 0)
        {
            return -1;
        }
        i++;
    }
    for (size_t j = x; j < vec.size - 1; j++)
    {
        if (vec.data[j] < vec.data[j + 1] || vec.data[j] < 0
            || vec.data[j + 1] < 0)
        {
            return -1;
        }
    }
    x = hill_max(vec);
    return x;
}

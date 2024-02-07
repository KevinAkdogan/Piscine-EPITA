#include "int_vector_vice_max.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int int_vector_vice_max(const struct int_vector vec)
{
    int max = vec.data[1];
    int vice_max = vec.data[0];

    if (vec.size > 2)
    {
        for (size_t i = 0; i < vec.size; i++)
        {
            if (vec.data[i] > max)
            {
                vice_max = max;
                max = vec.data[i];
            }

            else if (vec.data[i] < max && vec.data[i] > vice_max)
            {
                vice_max = vec.data[i];
            }
        }
    }
    return vice_max;
}

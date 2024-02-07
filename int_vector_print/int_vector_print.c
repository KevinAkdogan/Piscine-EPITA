#include "int_vector_print.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void int_vector_print(const struct int_vector vec)
{
    if (vec.size > 0)
    {
        for (size_t i = 0; i < vec.size; i++)
        {
            printf("%d", vec.data[i]);
            if (i < vec.size - 1)
            {
                printf(" ");
            }
        }
    }
    printf("\n");
}

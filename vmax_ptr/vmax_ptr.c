#include "vmax_ptr.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int vmax(const int *ptr, size_t size)
{
    int max = ptr[1];
    int vice_max = ptr[0];

    if (size > 0)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (ptr[i] > max)
            {
                vice_max = max;
                max = ptr[i];
            }
            else if (ptr[i] < max && ptr[i] > vice_max)
            {
                vice_max = ptr[i];
            }
        }
    }
    return vice_max;
}

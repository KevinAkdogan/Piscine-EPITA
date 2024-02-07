#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int binary_search(const int vec[], size_t size, int elt)
{
    if (size > 0)
    {
        int g = 0;
        int d = size - 1;
        while (g <= d)
        {
            int mid = (g + d) / 2;
            if (elt == vec[mid])
                return mid;
            else if (elt < vec[mid])
                d = mid - 1;
            else
                g = mid + 1;
        }
    }
    return -1;
}

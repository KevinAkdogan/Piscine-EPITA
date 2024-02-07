#include "bsearch.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int *binary_search(int *begin, int *end, int elt)
{
    int *b_search = &elt;
    int idx = 0;

    if (begin == end)
        return begin;

    while ((b_search == &elt) && (begin != end))
    {
        idx++;
        int *p = begin + (end - begin) / 2;

        if (*p > elt)
        {
            end = p;
        }
        else if (*p == elt)
        {
            b_search = p;
        }
        else
        {
            begin = p + 1;
        }
    }
    if (b_search == &elt)
    {
        idx--;
        return begin;
    }
    return b_search;
}

#include "lca.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

static int lca_second(int *values, int length, int p, int q, int x)
{
    if (x >= length)
    {
        return -1;
    }
    if (values[x] == q || values[x] == p)
    {
        return values[x];
    }
    int l = -1;
    int r = -1;
    if (2 * x + 2 < length)
    {
        r = lca_second(values, length, p, q, 2 * x + 2);
    }
    if (2 * x + 1)
    {
        l = lca_second(values, length, p, q, 2 * x + 1);
    }
    if (r != -1 && l != -1)
    {
        return values[x];
    }
    if (l != -1)
        return l;
    else
        return r;
}

int lca(int *values, int length, int p, int q)
{
    return lca_second(values, length, p, q, 0);
}

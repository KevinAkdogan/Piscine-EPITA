#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

void plus_equal(int *a, int *b)
{
    if (a == NULL && b == NULL)
        return;
    else if (a == NULL || b == NULL)
        return;
    else
        *a += *b;
}

void minus_equal(int *a, int *b)
{
    if (a == NULL && b == NULL)
        return;
    else if (a == NULL || b == NULL)
        return;
    else
        *a -= *b;
}

void mult_equal(int *a, int *b)
{
    if (a == NULL && b == NULL)
        return;
    else if (a == NULL || b == NULL)
        return;
    else
        *a *= *b;
}

int div_equal(int *a, int *b)
{
    if (a == NULL || b == NULL || *b == 0)
        return 0;
    int d = (*a % *b);
    *a /= *b;
    return d;
}

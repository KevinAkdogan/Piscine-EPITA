#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

int *my_calloc(size_t size, int init)
{
    if (size == 0)
        return NULL;

    int res = 0;
    int *x = NULL;

    __builtin_mul_overflow(sizeof(init), size, &res);
    x = malloc(res);

    if (!x)
        return NULL;
    for (size_t i = 0; i < size; i++)
    {
        x[i] = init;
    }
    return x;
}

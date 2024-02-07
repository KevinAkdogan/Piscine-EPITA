#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int foldl(int *array, size_t len, int (*func)(int, int))
{
    size_t i;
    int x = 0;
    for (i = 0; i < len; i++)
    {
        x = func(x, array[i]);
    }
    return x;
}

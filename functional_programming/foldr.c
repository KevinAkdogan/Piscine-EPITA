#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int foldr(int *array, size_t len, int (*func)(int, int))
{
    size_t i;
    int x = 0;
    for (i = len; i > 0; i--)
    {
        x = (*func)(array[i - 1], x);
    }
    return x;
}

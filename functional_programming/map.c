#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

void map(int *array, size_t len, void (*func)(int *))
{
    size_t i;
    for (i = 0; i < len; i++)
    {
        (*func)(&array[i]);
    }
}

#include "my_memmove.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

void *my_memmove(void *dest, const void *src, size_t n)
{
    char *pdest = dest;
    const char *psrc = src;

    if (psrc < pdest)
    {
        psrc += n;
        pdest += n;
        while (n--)
        {
            *--pdest = *--psrc;
        }
    }
    else
    {
        while (n--)
        {
            *pdest++ = *psrc++;
        }
    }
    return dest;
}

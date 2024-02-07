#include <stddef.h>

void *my_memcpy(void *dest, const void *source, size_t num)
{
    const char *s = source;
    char *d = dest;
    size_t i;

    for (i = 0; i < num; i++)
    {
        d[i] = s[i];
    }
    return dest;
}

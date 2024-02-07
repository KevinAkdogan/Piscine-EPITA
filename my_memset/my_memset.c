#include <stddef.h>

void *my_memset(void *s, int c, size_t n)
{
    unsigned char *p = s;

    if (p == NULL)
        return NULL;

    while (n > 0)
    {
        *p = c;
        p++;
        n--;
    }
    return s;
}

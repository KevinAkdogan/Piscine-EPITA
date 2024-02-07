#include <stddef.h>

size_t strlen(const char *s)
{
    int idx = 0;
    while (s[idx] != '\0')
    {
        idx++;
    }
    return idx;
}

char *my_strcpy(char *dest, const char *source)
{
    size_t idx1;

    if (source == NULL)
    {
        return NULL;
    }

    for (idx1 = 0; idx1 < strlen(source); idx1++)
    {
        dest[idx1] = source[idx1];
    }
    dest[idx1] = '\0';
    return dest;
}

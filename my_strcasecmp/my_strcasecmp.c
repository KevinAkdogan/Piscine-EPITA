#include "my_strcasecmp.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int my_strcasecmp(const char *s1, const char *s2)
{
    int i = 0;
    int j = 0;
    while (s1[i] != 0)
    {
        i++;
    }
    while (s2[j] != 0)
    {
        j++;
    }
    return i - j;
}

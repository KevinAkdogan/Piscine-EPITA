#include "my_strstr.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int my_strlen(const char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
    {
        i = i + 1;
    }
    if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
    {
        return 0;
    }
    else if (s1[i] > s2[i])
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int my_strstr(const char *haystack, const char *needle)
{
    int i = 0;

    if (needle[0] == '\0' || needle[0] == '\0')
    {
        return 0;
    }

    while (i < my_strlen(haystack))
    {
        if (haystack[i] == *needle)
        {
            if (!my_strncmp(haystack + i, needle, my_strlen(needle)))
            {
                return i;
            }
        }
        i++;
    }
    return -1;
}

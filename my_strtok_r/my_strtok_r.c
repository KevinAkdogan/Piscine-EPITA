#include "my_strtok_r.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

size_t my_strspn(const char *s, const char *accept)
{
    size_t i;
    size_t j;
    for (i = 0; s[i]; i++)
    {
        for (j = 0; accept[j]; j++)
        {
            if (s[i] == accept[j])
                break;
        }
        if (!accept[j])
            break;
    }
    return i;
}

const char *my_strchr(const char *s, char n)
{
    const char *c_find = NULL;
    if (s != NULL)
    {
        do
        {
            if (*s == n)
            {
                c_find = s;
                break;
            }
        } while (*s++);
    }
    return c_find;
}

size_t my_strcspn(const char *s1, const char *s2)
{
    size_t len = 0;

    if ((s1 == NULL) || (s2 == NULL))
    {
        return len;
    }

    while (*s1)
    {
        if (my_strchr(s2, *s1))
            return len;

        else
            s1++;
        len++;
    }
    return len;
}

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    char *end;

    if (str == NULL)
        str = *saveptr;

    if (*str == '\0')
    {
        *saveptr = str;
        return NULL;
    }

    str += my_strspn(str, delim);
    if (*str == '\0')
    {
        *saveptr = str;
        return NULL;
    }

    end = str + my_strcspn(str, delim);
    if (*end == '\0')
    {
        *saveptr = end;
        return str;
    }

    *end = '\0';
    *saveptr = end + 1;
    return str;
}

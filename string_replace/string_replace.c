#include "string_replace.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

size_t my_strlen(const char *s)
{
    size_t i = 0;
    while (s[i] != 0)
    {
        i++;
    }
    return i;
}

int rep(char c, const char *s, size_t size)
{
    int cnt = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (s[i] == c)
        {
            cnt++;
        }
    }
    return cnt;
}

char *string_replace(char c, const char *str, const char *pattern)
{
    int i = 0;
    if (str == NULL)
        return NULL;
    if (str[0] == '\0')
    {
        char *n = malloc(sizeof(char));
        n[0] = '\0';
        return n;
    }
    size_t l_str = my_strlen(str);
    size_t l_pat = 0;
    if (pattern != NULL)
        l_pat = my_strlen(pattern);
    int rp = rep(c, str, l_str);

    char *n = malloc(sizeof(char) * (l_str + (l_pat - 1) * rp + 1));
    for (size_t k = 0; k < l_str; k++)
    {
        if (str[k] == c)
        {
            for (size_t j = 0; j < l_pat; j++)
            {
                n[i] = pattern[j];
                i++;
            }
        }
        else
        {
            n[i] = str[k];
            i++;
        }
    }
    n[i] = '\0';
    return n;
}

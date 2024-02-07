#include "my_itoa_base.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int my_strlen(const char *str)
{
    int idx = 0;
    while (str[idx] != '\0')
    {
        idx++;
    }
    return idx;
}

int my_strcmp(const char *s1, const char *s2)
{
    if (my_strlen(s1) > my_strlen(s2))
    {
        return 1;
    }

    else if (my_strlen(s1) == my_strlen(s2))
    {
        return 0;
    }

    else
    {
        return -1;
    }
}

void str_revert(char *str)
{
    int size = my_strlen(str);
    for (int idx = 0; idx < size / 2; idx++)
    {
        char tmp = str[idx];
        str[idx] = str[size - idx - 1];
        str[size - idx - 1] = tmp;
    }
}

char *my_itoa_base(int n, char *s, const char *base)
{
    int idx = 0;
    int b = my_strlen(base);

    if (n == 0)
    {
        s[idx++] = '0';
        s[idx] = '\0';
        return s;
    }

    int sign = n;
    if (sign < 0 && b == 10)
        n = -n;

    int res = 0;
    while (n > 0)
    {
        res = n % b;
        if (res >= 10 && my_strcmp(base, "0123456789abcdef") == 0)
        {
            s[idx] = 97 + (res - 10);
        }

        else if (res >= 10 && my_strcmp(base, "0123456789ABCDEF") == 0)
        {
            s[idx] = 65 + (res - 10);
        }

        else
        {
            s[idx] = res + '0';
        }
        n /= b;
        idx++;
    }
    if (b == 10 && sign < 0)
    {
        s[idx++] = '-';
    }
    s[idx] = '\0';
    str_revert(s);
    return s;
}

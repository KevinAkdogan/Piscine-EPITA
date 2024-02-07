#include "my_itoa.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

char *my_itoa(int value, char *s)
{
    int i = 0;
    for (int x = value; x != 0; x = x / 10)
    {
        i++;
    }
    int y = 0;
    if (value == 0)
    {
        s[0] = value + 48;
        s[1] = '\0';
    }
    else if (value > 0)
    {
        while (y < i)
        {
            char z = value % 10 + 48;
            s[i - y - 1] = z;
            value = value / 10;
            y++;
        }
        s[i] = '\0';
    }
    else
    {
        value = -value;
        for (int t = 0; t < i; t++)
        {
            s[i - t] = value % 10 + 48;
            value = value / 10;
        }
        int a = 45;
        s[0] = a;
        s[i + 1] = '\0';
    }
    return s;
}

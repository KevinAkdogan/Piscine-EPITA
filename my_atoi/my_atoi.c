#include "my_atoi.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int my_pow(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    else if (a == 0)
    {
        return 0;
    }
    else
    {
        return a * my_pow(a, b - 1);
    }
}

int my_atoi(const char *str)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int u = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            a++;
        }
    }
    for (int j = 0; str[j] != 0; j++)
    {
        if (j > 0 && str[j] == ' ' && str[j - 1] != ' ')
        {
            return 0;
        }
        else if (str[j] == ' ')
        {
            continue;
        }
        else if (str[j] >= '0' && str[j] <= '9')
        {
            b += (str[j] - '0') * my_pow(10, a - 1);
            a--;
        }
        else if (str[j] == '-' || str[j] == '+')
        {
            c = j;
            u++;
        }
        else
            return 0;
    }
    if (u > 1)
        return 0;
    else if (str[c] == '-')
        return -b;
    else
        return b;
}

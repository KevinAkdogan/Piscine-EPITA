#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int hill_max(int tab[], size_t len)
{
    int i = 0;
    for (size_t j = 0; j < len; j++)
    {
        if (tab[j] > tab[i])
            i = j;
    }
    return i;
}

int top_of_the_hill(int tab[], size_t len)
{
    int size = len;
    int i = 0;
    int x = 0;

    if (len > 0)
    {
        while (tab[i] <= tab[i + 1])
        {
            if (i + 1 == size)
            {
                x = len;
            }
            else
            {
                x = i + 1;
            }
            i++;
        }
        for (size_t j = x; j < len - 1; j++)
        {
            if (tab[j] < tab[j + 1])
                return -1;
        }
    }
    x = hill_max(tab, len);
    return x;
}

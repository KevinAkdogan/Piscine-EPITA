#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int pine(unsigned n)
{
    if (n < 3)
        return 1;
    else
    {
        unsigned a = 0;
        while (a < n)
        {
            unsigned b = 0;
            while (b < n - a - 1)
            {
                putchar(32);
                b++;
            }
            unsigned c = 0;
            while (c < a * 2 + 1)
            {
                putchar(42);
                c++;
            }
            putchar(10);
            a++;
        }
        unsigned d = 0;
        while (d < n / 2)
        {
            unsigned e = 0;
            while (e < n - 1)
            {
                putchar(32);
                e++;
            }
            putchar(42);
            putchar(10);
            d++;
        }
    }
    return 0;
}

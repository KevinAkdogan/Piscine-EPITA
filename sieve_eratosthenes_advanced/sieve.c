#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n < 2)
    {
        return;
    }

    int *len = malloc(sizeof(n));

    for (int idx = 2; idx < n + 1; idx++)
    {
        int p = 0;
        for (int idx2 = 2; idx2 < idx + 1; idx2++)
        {
            if (idx % idx2 == 0)
            {
                p += 1;
            }
        }
        if (p == 1)
        {
            printf("%d\n", idx);
        }
    }
    free(len);
}

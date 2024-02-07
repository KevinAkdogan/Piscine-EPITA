#include <stdio.h>

void sieve(int n)
{
    if (n < 2)
    {
        return;
    }
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
}

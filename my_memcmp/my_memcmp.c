#include <stddef.h>

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    const char *ss1 = s1;
    const char *ss2 = s2;

    if (num == 0)
    {
        return 0;
    }

    while (num > 0)
    {
        if (*ss1 != *ss2)
        {
            return (*ss1 - *ss2);
        }
        num--;
        ss1++;
        ss2++;
    }
    return 0;
}

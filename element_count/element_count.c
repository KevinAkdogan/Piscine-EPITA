#include <stddef.h>

size_t element_count(int *begin, int *end)
{
    size_t cnt = 0;
    int *tmp = begin;

    while (*tmp != *end)
    {
        cnt++;
        tmp++;
    }
    return cnt;
}

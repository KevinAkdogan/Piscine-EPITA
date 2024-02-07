#include <stddef.h>

size_t my_strlen(const char str[])
{
    size_t idx = 0;
    while (str[idx] != '\0')
    {
        idx++;
    }
    return idx;
}

void str_revert(char str[])
{
    int size = my_strlen(str);
    for (int idx = 0; idx < size / 2; idx++)
    {
        char tmp = str[idx];
        str[idx] = str[size - idx - 1];
        str[size - idx - 1] = tmp;
    }
}

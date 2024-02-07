#include <stddef.h>

size_t my_strlen(const char *s)
{
    int idx = 0;
    while (s[idx] != '\0')
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

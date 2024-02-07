#include <stddef.h>

size_t my_strspn(const char *s, const char *accept)
{
    size_t i;
    size_t j;
    for (i = 0; s[i]; i++)
    {
        for (j = 0; accept[j]; j++)
        {
            if (s[i] == accept[j])
                break;
        }
        if (!accept[j])
            break;
    }
    return i;
}

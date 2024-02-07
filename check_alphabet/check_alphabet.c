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

int check_alphabet(const char *str, const char *alphabet)
{
    if (alphabet == NULL)
    {
        return 1;
    }

    for (size_t idx1 = 0; idx1 < my_strlen(alphabet); idx1++)
    {
        int cnt = 0;
        for (size_t idx2 = 0; idx2 < my_strlen(str); idx2++)
        {
            cnt += 1;
            if (alphabet[idx1] == str[idx2])
            {
                break;
            }
            if (idx2 == my_strlen(str) - 1)
            {
                return 0;
            }
        }
        if (cnt == 0)
        {
            return 0;
        }
    }
    return 1;
}

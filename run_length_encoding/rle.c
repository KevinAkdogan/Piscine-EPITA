#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *rle_encode(const char *s)
{
    size_t max = 0;
    size_t len = strlen(s);
    char *dest = calloc(2 * len + 1, sizeof(char));
    if (dest == NULL)
        return NULL;
    for (size_t i = 0; i < len; i++)
    {
        int cnt = 1;
        while (i < len - 1 && s[i] == s[i + 1])
        {
            cnt += 1;
            i += 1;
        }
        while (cnt != 0)
        {
            if (cnt > 9)
            {
                dest[max] = 9 + '0';
                cnt -= 9;
                max += 1;
                dest[max] = s[i];
                max += 1;
            }
            else
            {
                dest[max] = cnt + '0';
                max += 1;
                dest[max] = s[i];
                max += 1;
                cnt = 0;
            }
        }
    }
    return dest;
}

char *rle_decode(const char *s)
{
    size_t len = strlen(s);
    char *dest = calloc(10 * len + 1, sizeof(char));
    if (dest == NULL)
        return NULL;
    int cnt = 0;
    for (size_t i = 0; i < len; i++)
    {
        size_t x = s[i] - '0';
        i += 1;
        for (size_t j = 0; j < x; j++, cnt++)
        {
            dest[cnt] = s[i];
        }
    }
    return dest;
}

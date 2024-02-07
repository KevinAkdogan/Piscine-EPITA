#include "vigenere.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

size_t strlen(const char *s)
{
    size_t i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

void cipher(const char *key, const char *msg, char *res)
{
    size_t size = strlen(key);
    size_t i;

    for (i = 0; msg[i] != '\0'; i++)
    {
        if (msg[i] <= 'z' && msg[i] >= 'a')
        {
            size_t rg = (msg[i] + key[i % size] - 2 * 'a') % 26;
            res[i] = 'a' + rg;
        }
        else if (msg[i] <= 'Z' && msg[i] >= 'A')
        {
            size_t rg = (msg[i] + key[i % size] - 'a' - 'A') % 26;
            res[i] = 'A' + rg;
        }
        else
        {
            res[i] = msg[i];
        }
    }
    res[i] = '\0';
}

void decipher(const char *key, const char *msg, char *res)
{
    size_t size = strlen(key);
    char ktmp[size + 1];
    size_t i;

    for (i = 0; key[i] != 0; i++)
    {
        int rg = (26 - (key[i] - 'a')) % 26;
        ktmp[i] = rg + 'a';
    }
    ktmp[i] = '\0';
    cipher(ktmp, msg, res);
}

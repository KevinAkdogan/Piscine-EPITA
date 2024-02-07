#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

void my_rol_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    size_t i = 0;
    size_t j = 0;
    char *c = data;
    const char *k = key;

    while (i < data_len)
    {
        j %= key_len;
        c[i] += k[j];
        i++;
        j++;
    }
}

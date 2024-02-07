#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

unsigned char rol(unsigned char value, unsigned char roll)
{
    while (roll)
    {
        value = value << 1 | value >> 7;
        roll--;
    }
    return value;
}

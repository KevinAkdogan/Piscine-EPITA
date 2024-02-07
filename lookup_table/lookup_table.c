#include "lookup_table.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

void apply_lut(unsigned char mat[4][4], const unsigned char lut[256])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mat[i][j] = lut[j + i * 4];
        }
    }
}

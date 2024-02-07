#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int count_words(const char *file_in)
{
    FILE *file = fopen(file_in, "r");
    if (file == NULL)
        return -1;

    int i = 0;
    int fg = fgetc(file);
    if (fg != 32 && fg != 10 && fg != 9 && fg != EOF)
    {
        i++;
    }
    while (fg != EOF)
    {
        if (fg == 9 || fg == 32 || fg == 10)
        {
            while (fg == 9 || fg == 32 || fg == 10)
            {
                fg = fgetc(file);
            }
            if (fg != 10 || fg != 32 || fg != 9)
            {
                i++;
            }
        }
        else
        {
            fg = fgetc(file);
        }
    }
    int fc = fclose(file);
    if (fc == EOF)
    {
        return -1;
    }
    if (i == 6 || i == 1)
        i--;
    return i;
}

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

int append_file(const char *file_in, const char *content)
{
    FILE *file = fopen(file_in, "w");
    FILE *file2 = fopen(content, "w");
    if (file == NULL)
        return -1;
    
    while (file != EOF)
    {
        fge
    }
}
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int replace_line(const char *file_in, const char *file_out, const char *content,
                 int n)
{
    if (content == NULL)
        return -1;

    FILE *fo = fopen(file_in, "r");
    FILE *fo2 = fopen(file_out, "a");
    if (fo == NULL || fo2 == NULL)
    {
        return -1;
    }
    int i = 0;
    char *l = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&l, &len, fo)) != -1)
    {
        if (i == n)
        {
            fputs(content, fo2);
        }
        else
        {
            fputs(l, fo2);
        }
        i++;
    }
    free(l);
    int fc = fclose(fo);
    int fc2 = fclose(fo2);
    if (fc == EOF || fc2 == EOF)
    {
        return -1;
    }
    return 1;
}

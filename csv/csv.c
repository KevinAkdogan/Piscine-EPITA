#define _GNU_SOURCE
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    FILE *fo = fopen(argv[1], "r");
    if (fo == NULL)
        return 1;
    size_t length = 0;
    char *buff;
    while (getline(&buff, &length, fo) != -1)
    {
        char *s;
        int max = 0;
        char *tiktok = strtok_r(buff, ",", &s);
        if (tiktok == NULL)
        {
            return 1;
        }
        max = atoi(tiktok);
        while (tiktok)
        {
            int data = atoi(tiktok);
            if (data > max)
            {
                max = data;
            }
            else
            {
                tiktok = strtok_r(NULL, ",", &s);
            }
        }
        printf("%d\n", max);
    }
    fclose(fo);
    return 0;
}

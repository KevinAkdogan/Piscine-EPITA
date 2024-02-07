#include <stddef.h>
#include <stdlib.h>

size_t my_strlen(const char *s)
{
    size_t i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

void foo(int *mat[], size_t s1, size_t s2)
{
    size_t i;
    for (i = 0; i < s1; i++)
    {
        mat[i][0] = i;
    }
    for (i = 0; i < s2; i++)
    {
        mat[0][i] = i;
    }
}

void free_mt(int *mat[], size_t lomg)
{
    for (size_t i = 0; i < lomg + 1; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

size_t levenshtein(const char *s1, const char *s2)
{
    int **mat = malloc(sizeof(int *) * (my_strlen(s1) + 1));
    for (size_t i = 0; i < my_strlen(s1) + 1; i++)
    {
        mat[i] = malloc(sizeof(int) * (my_strlen(s2) + 1));
    }
    foo(mat, my_strlen(s1) + 1, my_strlen(s2) + 1);
    for (size_t i = 1; i <= my_strlen(s1); i++)
    {
        char c1 = s1[i - 1];
        for (size_t j = 1; j <= my_strlen(s2); j++)
        {
            char c2 = s2[j - 1];
            if (c1 == c2)
                mat[i][j] = mat[i - 1][j - 1];
            else
            {
                int del = mat[i - 1][j] + 1;
                int ins = mat[i][j - 1] + 1;
                int sub = mat[i - 1][j - 1] + 1;
                int minim = del;
                if (ins < minim)
                {
                    minim = ins;
                }

                if (sub < minim)
                {
                    minim = sub;
                }
                mat[i][j] = minim;
            }
        }
    }
    size_t res = mat[my_strlen(s1)][my_strlen(s2)];
    free_mt(mat, my_strlen(s1));
    return res;
}

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int *zigzag(size_t n)
{
    int *arr = malloc(sizeof(n));
    int x = 0;

    if (n == 0)
        return 0;

    for (size_t z = 0; z < n; z++)
    {
        if (z % 2 == 0)
        {
            for (size_t y = 0; y <= z; y++)
            {
                *((arr + (z - y) * n) + y) = x++;
            }
        }
        else
        {
            for (size_t y = 0; y <= z; y++)
            {
                *((arr + y * n) + z - y) = x++;
            }
        }
    }
    for (size_t z = 1; z < n; z++)
    {
        if (z % 2 == n % 2)
        {
            for (size_t y = 1; y <= n - z; y++)
            {
                *((arr + (z + y - 1) * n) + n - y) = x++;
            }
        }
        else
        {
            for (size_t y = 1; y <= n - z; y++)
            {
                *((arr + (n - y) * n) + z + y - 1) = x++;
            }
        }
    }
    return arr;
}

void print_matrix(const int *matrix, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
            printf("%4d", matrix[i * n + j]);
        printf("\n");
    }
}

int main(void)
{
    printf("zigzag of size 3:\n");
    int *zig3 = zigzag(3);
    print_matrix(zig3, 3);
    free(zig3);

    printf("zigzag of size 5:\n");
    int *zig5 = zigzag(5);
    print_matrix(zig5, 5);
    free(zig5);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

/* This function display a `matrix` of size `n` */
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

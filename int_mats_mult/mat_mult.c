#include <stddef.h>

void mat_mult(int **mat1, int **mat2, size_t *matrices_size, int **out)
{
    size_t i;
    size_t j;
    size_t k;

    for (i = 0; i < matrices_size[0]; i++)
    {
        for (j = 0; j < matrices_size[2]; j++)
        {
            for (k = 0; k < matrices_size[1]; k++)
            {
                out[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

#include "complex_print.h"

#include <stdio.h>

void print_complex(struct complex a)
{
    if (a.img >= 0)
    {
        printf("complex(%.2f + %.2fi)", a.real, a.img);
    }
    if (a.img < 0)
    {
        float p_img = -a.img;
        printf("complex(%.2f - %.2fi)", a.real, p_img);
    }
    return;
}

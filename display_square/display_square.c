#include <stdio.h>
void display_square(int width)
{
    int i;
    int j;
    int w = width;
    if (width <= 0)
    {
        return;
    }
    if (w % 2 == 0)
    {
        w++;
    }
    for (i = 0; i < (w + 1) / 2; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (i == 0 || i == w / 2 || j == 0 || j == w - 1)
            {
                putchar('*');
            }
            else
            {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

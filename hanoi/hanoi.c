#include <stdio.h>

void move(int nd, char x, char y, char z)
{
    if (nd == 1)
    {
        putchar(x);
        putchar('-');
        putchar('>');
        putchar(z);
        putchar('\n');
    }
    else
    {
        move(nd - 1, x, z, y);
        move(1, x, y, z);
        move(nd - 1, y, x, z);
    }
}

void hanoi(unsigned int n)
{
    move(n, '1', '2', '3');
}

#include <stdio.h>

int main(void)
{
    char c;
    for (c = 'a'; c <= 'z'; c++)
    {
        if (c == 'z')
        {
            putchar(c);
        }
        else
        {
            putchar(c);
            putchar(' ');
        }
    }
    putchar('\n');
    return 0;
}

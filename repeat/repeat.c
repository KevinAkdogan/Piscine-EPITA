#include <stdio.h>
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        return 1;
    }
    int j = 0;
    while (argv[2][j] != '\0')
    {
        j++;
    }
    if (j != 1)
    {
        return 0;
    }
    for (int i = 1; i <= *argv[2] - '0'; i++)
    {
        puts(argv[1]);
    }
    return 0;
}

#include <stdio.h>

int main(int argc, char *args[])
{
    if (argc == 1)
    {
        printf("Hello World!\n");
    }
    else
    {
        for (int i = 1; i <= argc - 1; i++)
        {
            printf("Hello %s!\n", args[i]);
        }
    }
    return 0;
}

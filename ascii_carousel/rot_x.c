#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>

size_t strlen(const char *s)
{
    size_t i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

void rot_x(char *s, int x)
{
    if (s == NULL)
        return;

    
}

int main()
{
    char in[] = "Shhh ShE is ZZZzZ059%";
    printf("In: %s\n", in);
    rot_x(in, 13);
    printf("Out: %s\n", in);
    return 0;
}

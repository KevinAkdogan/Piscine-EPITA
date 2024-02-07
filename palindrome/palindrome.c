#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

int palindrome(const char *s)
{
    if (s == NULL)
        return 0;
    int i = 0;
    while (s[i] != 0)
    {
        i++;
    }
    if (i == 0)
        return 1;
    int k = 0;
    int j = i - 1;
    while (k <= j)
    {
        if (s[k] > 90 && s[k] < 97)
            k++;
        else if (s[k] < 65 || s[k] > 122)
            k++;
        else if (s[j] > 90 && s[j] < 97)
            j--;
        else if (s[j] < 65 || s[j] > 122)
            j--;
        else if (s[j] != s[k])
            return 0;
        else
        {
            k++;
            j--;
        }
    }
    return 1;
}

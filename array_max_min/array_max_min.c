#include <stddef.h>
void array_max_min(int tab[], size_t len, int *max, int *min)
{
    if (tab == NULL && len == 0)
    {
        return;
    }
    size_t i;
    *max = tab[0];
    *min = tab[0];
    for (i = 0; i < len; i++)
    {
        if (tab[i] >= *max)
        {
            *max = tab[i];
        }
        else if (tab[i] <= *min)
        {
            *min = tab[i];
        }
    }
}

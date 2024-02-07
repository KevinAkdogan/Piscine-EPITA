#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

typedef int (*f_cmp)(const void *, const void *);

void insertion_sort(void **array, f_cmp comp)
{
    if (*array == NULL)
        return;

    int i = 1;
    int j;
    while (array[i])
    {
        void *elm = array[i];
        j = i;
        while (j > 0 && (comp(array[j - 1], elm) > 0))
        {
            array[j] = array[j - 1];
            j = j - 1;
        }
        array[j] = elm;
        i++;
    }
}

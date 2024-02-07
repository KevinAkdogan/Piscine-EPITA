#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

void swap(int *arr, int x, int y)
{
    int tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}

unsigned array_min(int arr[], unsigned start, unsigned size)
{
    int min = arr[start];
    unsigned idx_min = start;
    for (unsigned i = start; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            idx_min = i;
        }
    }
    return idx_min;
}

void selection_sort(int arr[], unsigned size)
{
    unsigned i;

    for (i = 0; i < size; i++)
    {
        unsigned idx_min = array_min(arr, i, size);
        swap(arr, idx_min, i);
    }
}

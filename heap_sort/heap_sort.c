#include "heap_sort.h"

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

void heapify2(int *array, size_t size, size_t i)
{
    size_t larg = i;
    size_t right = 2 * i + 2;
    size_t left = 2 * i + 1;

    if (size == 0)
        return;

    if ((left < size) && (array[left] > array[larg]))
    {
        larg = left;
    }

    if ((right < size) && (array[right] > array[larg]))
    {
        larg = right;
    }

    if (larg != i)
    {
        swap(array, i, larg);
        heapify2(array, size, larg);
    }
}

void heapify(int *array, size_t size)
{
    int len = (size / 2) - 1;
    for (int i = len; i >= 0; i--)
    {
        heapify2(array, size, i);
    }
}

void heap_sort(int *array, size_t size)
{
    if (size == 0)
        return;

    heapify(array, size);
    for (int i = size - 1; i >= 1; i--)
    {
        swap(array, 0, i);
        heapify2(array, i, 0);
    }
}

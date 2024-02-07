#include "heap.h"

static int p(int a)
{
    return (a - 1) / 2;
}

static void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void add(struct heap *heap, int val)
{
    if (heap)
    {
        if (heap->size >= heap->capacity)
        {
            heap->array =
                realloc(heap->array, 2 * (heap->capacity) * sizeof(int));
            heap->capacity *= 2;
        }
        heap->array[heap->size] = val;
        heap->size += 1;
        int k = heap->size - 1;
        while (k != 0 && heap->array[p(k)] < heap->array[k])
        {
            swap(&heap->array[p(k)], &heap->array[k]);
            k = p(k);
        }
    }
}

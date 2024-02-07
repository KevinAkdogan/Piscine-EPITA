#include "heap.h"

static int lc(int i)
{
    return 2 * i + 1;
}

static int rc(int i)
{
    return 2 * i + 2;
}

static void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

static void heapify(struct heap *h, int i)
{
    size_t l = lc(i);
    size_t r = rc(i);
    int m = i;
    if (l < h->size && h->array[l] > h->array[i])
        m = l;

    if (r < h->size && h->array[r] > h->array[m])
        m = r;

    if (m != i)
    {
        swap(&h->array[i], &h->array[m]);
        heapify(h, m);
    }
}

int pop(struct heap *heap)
{
    assert(heap != NULL);
    assert(heap->size > 0);
    if (heap->size == 1)
    {
        (heap->size)--;
        return heap->array[0];
    }
    int r = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    (heap->size)--;
    heapify(heap, 0);
    return r;
}

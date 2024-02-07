#include "heap.h"

static int left(int i)
{
    return 2 * i + 1;
}

static int right(int i)
{
    return 2 * i + 2;
}

static void print_a(int a)
{
    if (a < 0)
    {
        putchar('-');
        a = -a;
    }
    if (a / 10)
    {
        print_a(a / 10);
    }
    putchar(a % 10 + '0');
}

static void printOrd(int *arr, size_t i, size_t size)
{
    if (i >= size)
    {
        return;
    }
    putchar(' ');
    print_a(arr[i]);

    printOrd(arr, left(i), size);

    printOrd(arr, right(i), size);
}

void print_heap(const struct heap *heap)
{
    if (heap)
    {
        if (heap->size > 0)
        {
            print_a(heap->array[0]);
            printOrd(heap->array, 1, heap->size);
            printOrd(heap->array, 2, heap->size);
            putchar('\n');
        }
    }
}

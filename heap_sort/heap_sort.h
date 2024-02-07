#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <stddef.h>

void swap(int *arr, int x, int y);
void heapify2(int *array, size_t size, size_t i);
void heapify(int *array, size_t size);
void heap_sort(int *array, size_t size);

#endif

#ifndef HEAP_H
#define HEAP_H

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct heap
{
    size_t size;
    size_t capacity;
    int *array;
};

struct heap *create_heap(void);
void add(struct heap *heap, int val);
int pop(struct heap *heap);
void delete_heap(struct heap *heap);
void print_heap(const struct heap *heap);

#endif /* !HEAP_H */

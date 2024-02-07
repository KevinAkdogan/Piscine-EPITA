#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void vector_print(const struct vector *v)
{
    size_t i = 0;
    if (v->size != 0)
    {
        for (; i < (v->size - 1); i++)
        {
            printf("%d,", v->data[i]);
        }

        printf("%d", v->data[i]);
    }
    puts("");
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    vector_destroy(v);
    struct vector *vr = vector_init(n);
    return vr;
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (!v)
        return NULL;
    if (i > v->size)
        return NULL;
    if (i == v->size)
        return vector_append(v, elt);
    if (v->size == v->capacity)
    {
        struct vector *tmp = vector_resize(v, v->capacity * 2);
        if (!tmp)
            return NULL;
        v = tmp;
    }
    for (size_t j = v->size; j > i; j--)
    {
        v->data[j] = v->data[j - 1];
    }
    v->data[i] = elt;
    v->size += 1;
    return v;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (!v)
        return NULL;
    if (i >= v->size)
        return NULL;
    for (size_t j = i; j < v->size - 1; j++)
    {
        v->data[j] = v->data[j + 1];
    }
    v->size -= 1;
    if (v->size < v->capacity / 2)
        vector_resize(v, v->capacity / 2);
    return v;
}

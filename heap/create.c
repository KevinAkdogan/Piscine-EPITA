#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *ch = malloc(sizeof(struct heap));
    if (!ch)
    {
        return NULL;
    }
    ch->size = 0;
    ch->capacity = 8;
    ch->array = malloc((8 * sizeof(int)));
    if (!(ch->array))
    {
        free(ch);
        return NULL;
    }
    return ch;
}

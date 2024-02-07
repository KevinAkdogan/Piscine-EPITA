#include "list.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *prep = malloc(sizeof(struct list));
    if (!prep)
    {
        return NULL;
    }
    prep->data = malloc(data_size);
    if (!prep->data)
    {
        return NULL;
    }
    memcpy(prep->data, value, data_size);
    prep->next = list;
    return prep;
}

size_t list_length(struct list *list)
{
    size_t length = 0;

    if (list == NULL)
    {
        return 0;
    }

    while (list != NULL)
    {
        list = list->next;
        length++;
    }
    return length;
}

void list_destroy(struct list *list)
{
    if (list == NULL)
    {
        return;
    }
    while (list != NULL)
    {
        struct list *destroy = list->next;
        free(list->data);
        free(list);
        list = destroy;
    }
    return;
}

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

#include "list.h"

void list_print(struct list *l)
{
    if (l == NULL)
    {
        printf("\n");
        return;
    }
    while (l->next != NULL)
    {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("%d\n", l->data);
}

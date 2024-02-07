#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

void fifo_clear(struct fifo *fifo)
{
    struct list *fc = fifo->head;

    while (fc != NULL)
    {
        struct list *var = fc;
        fc = fc->next;
        free(var);
    }

    fifo->head = NULL;
    fifo->size = 0;
    fifo->tail = NULL;
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);
    free(fifo);
}

void fifo_print(const struct fifo *fifo)
{
    if (fifo->size == 0)
        printf("\n");

    struct list *fp = fifo->head;

    while (fp != NULL)
    {
        if (fp->next != NULL)
        {
            printf("%d\n", fp->data);
        }
        else
        {
            printf("%d\n", fp->data);
        }
        fp = fp->next;
    }
}

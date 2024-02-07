#include "fifo.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

struct fifo *fifo_init(void)
{
    struct fifo *fi = malloc(sizeof(struct fifo));
    if (fi == NULL)
        return 0;
    else
    {
        fi->size = 0;
        fi->tail = NULL;
        fi->head = NULL;
    }
    return fi;
}

size_t fifo_size(struct fifo *fifo)
{
    if (fifo == NULL)
        return 0;
    else
        return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *fp = malloc(sizeof(struct list));
    if (fifo == NULL || fp == NULL)
        return;

    fp->data = elt;
    fp->next = NULL;

    if (fifo->head != NULL)
    {
        struct list *elm = fifo->head;
        while (elm->next != NULL)
        {
            elm = elm->next;
        }
        elm->next = fp;
    }
    else
    {
        fifo->head = fp;
    }
    fifo->size++;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (fifo == NULL)
        return;

    struct list *fp;

    if (fifo->head != NULL)
    {
        fp = fifo->head;
        fifo->head = fifo->head->next;
        free(fp);
    }
}

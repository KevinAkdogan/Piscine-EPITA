#include "stack.h"

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *new = malloc(sizeof(struct stack));
    new->next = s;
    new->data = e;
    return new;
}

struct stack *stack_pop(struct stack *s)
{
    if (s == NULL)
        return NULL;
    struct stack *t = s;
    struct stack *new_t = s->next;
    free(t);
    return new_t;
}

int stack_peek(struct stack *s)
{
    return s->data;
}

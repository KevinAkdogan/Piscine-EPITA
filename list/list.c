#include "list.h"

#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

struct list *list_add(struct list *l, int e)
{
    struct list *la = malloc(sizeof(struct list));
    if (la == NULL)
        return l;
    la->data = e;
    la->next = l;
    return la;
}

struct list *list_find(struct list *l, int e)
{
    if (l == NULL)
        return NULL;
    struct list *find = l;
    while (find != NULL && find->data != e)
    {
        find = find->next;
    }
    if (find == NULL)
    {
        return NULL;
    }
    if (find->data == e)
    {
        return find;
    }
    return NULL;
}

struct list *list_remove(struct list *l, int e)
{
    if (l == NULL)
        return NULL;
    struct list *le = l;
    struct list *lprev = l;
    if (l->data == e)
    {
        le = l->next;
        free(l);
        return le;
    }
    else
        le = le->next;
    while (le != NULL && le->data != e)
    {
        le = le->next;
        lprev = lprev->next;
    }
    if (le == NULL)
    {
        return l;
    }
    lprev->next = le->next;
    free(le);
    return l;
}

struct list *list_reverse_sorted_add(struct list *l, int e)
{
    if (l == NULL)
    {
        struct list *lrsa = malloc(sizeof(struct list));
        lrsa->data = e;
        lrsa->next = NULL;
        return lrsa;
    }
    struct list *le = l;
    struct list *lprev = l;
    if (l->data < e)
    {
        l = list_add(l, e);
        return l;
    }
    else
        le = le->next;
    while (le != NULL && le->data >= e)
    {
        le = le->next;
        lprev = lprev->next;
    }
    lprev->next = list_add(le, e);
    return l;
}

struct list *list_remove_if(struct list *l, int (*predicate)(int))
{
    if (l == NULL)
        return NULL;
    struct list *lr = l;
    while (lr != NULL)
    {
        if (predicate(lr->data))
        {
            int data = lr->data;
            lr = lr->next;
            l = list_remove(l, data);
        }
        else
            lr = lr->next;
    }
    return l;
}

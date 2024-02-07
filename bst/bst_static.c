#include "bst_static.h"

#include <stdio.h>
#include <stdlib.h>

struct bst *init(size_t capacity)
{
    struct bst *bst = malloc(sizeof(struct bst));
    bst->capacity = capacity;
    bst->size = 0;
    struct value **data = malloc(sizeof(struct value *) * capacity);
    for (size_t i = 0; i < capacity; i++)
    {
        data[i] = NULL;
    }
    bst->data = data;
    return bst;
}
struct value **data_rfl(size_t capacity, struct bst *tree)
{
    tree->capacity = capacity * 2 + 3;
    struct value **data2 =
        realloc(tree->data, sizeof(struct value *) * tree->capacity);
    if (data2 == NULL)
        return tree->data;
    for (size_t i = capacity; i < tree->capacity; i++)
    {
        data2[i] = NULL;
    }
    tree->data = data2;
    return tree->data;
}

void add(struct bst *tree, int value)
{
    if (tree == NULL)
        return;
    size_t cap = tree->capacity;
    size_t i = 0;
    if (cap == 0)
    {
        tree->data = data_rfl(0, tree);
    }
    while (tree->data[i])
    {
        if (tree->data[i]->val > value)
        {
            i = 2 * i + 1;
        }
        else if (tree->data[i]->val < value)
        {
            i = 2 * i + 2;
        }
        else
            return;
        if (i >= cap)
        {
            tree->data = data_rfl(cap, tree);
        }
    }
    struct value *vala = malloc(sizeof(struct value));
    vala->val = value;
    tree->size += 1;
    tree->data[i] = vala;
}

int search(struct bst *tree, int value)
{
    if (tree == NULL)
        return -1;
    size_t i = 0;
    while (tree->data[i])
    {
        if (tree->data[i]->val == value)
            return i;
        if (tree->data[i]->val > value)
            i = 2 * i + 1;
        else
            i = 2 * i + 2;
    }
    return -1;
}
void bst_free(struct bst *tree)
{
    if (tree == NULL)
        return;
    if (tree->size > 0)
    {
        size_t i = 0;
        while (i < tree->capacity)
        {
            if (tree->data[i])
            {
                free(tree->data[i]);
                tree->data[i] = NULL;
                if (tree->data[2 * i + 1])
                {
                    free(tree->data[2 * i + 1]);
                    tree->data[2 * i + 1] = NULL;
                }
                if (tree->data[2 * i + 2])
                {
                    free(tree->data[2 * i + 2]);
                    tree->data[2 * i + 2] = NULL;
                }
            }
            i++;
        }
    }
    free(tree->data);
    tree->data = NULL;
    free(tree);
}

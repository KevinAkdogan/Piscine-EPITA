#include "bst.h"

#include <stdlib.h>

struct bst_node *create_node(int value)
{
    struct bst_node *root = malloc(sizeof(struct bst_node));
    root->data = value;
    root->left = NULL;
    root->right = NULL;
    return root;
}

struct bst_node *add_node(struct bst_node *tree, int value)
{
    if (tree == NULL)
        return create_node(value);
    struct bst_node *treeprev = tree;
    struct bst_node *treeparc = tree;
    while (treeparc != NULL)
    {
        treeprev = treeparc;
        if (treeparc->data > value)
            treeparc = treeparc->left;

        else if (treeparc->data < value)
            treeparc = treeparc->right;
        else
            return tree;
    }
    if (treeprev->data > value)
    {
        treeprev->left = create_node(value);
    }
    else if (treeprev->data < value)
        treeprev->right = create_node(value);
    return tree;
}

struct bst_node *delete_node(struct bst_node *tree, int value)
{
    if (tree == NULL)
        return NULL;
    if (tree->data == value)
    {
        struct bst_node *elem = tree->left;
        if (elem == NULL)
        {
            elem = tree->right;
            free(tree);
            return elem;
        }
        struct bst_node *elem2 = tree;
        while (elem->right)
        {
            elem2 = elem;
            elem = elem->right;
        }
        elem->right = tree->right;
        elem2->right = elem->left;
        if (elem->data != tree->left->data)
            elem->left = tree->left;
        free(tree);
        return elem;
    }
    if (value < tree->data)
    {
        tree->left = (delete_node(tree->left, value));
    }
    else
        tree->right = (delete_node(tree->right, value));
    return tree;
}

const struct bst_node *find(const struct bst_node *tree, int value)
{
    if (tree == NULL)
        return NULL;
    while (tree != NULL)
    {
        if (tree->data == value)
            return tree;
        if (tree->data > value)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return NULL;
}

void free_bst(struct bst_node *tree)
{
    if (tree == NULL)
        return;
    struct bst_node *treel = tree->left;
    struct bst_node *treer = tree->right;
    free(tree);
    free_bst(treel);
    free_bst(treer);
}

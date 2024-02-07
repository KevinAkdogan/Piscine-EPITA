void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int par(int *tab, int l, int h)
{
    int p = tab[h];
    int i = l - 1;

    for (int j = l; j < h; j++)
    {
        if (tab[j] <= p)
        {
            i++;
            swap(&tab[i], &tab[j]);
        }
    }
    swap(&tab[i + 1], &tab[h]);
    return (i + 1);
}

void quicksort2(int *tab, int l, int h)
{
    if (l < h)
    {
        int p = par(tab, l, h);
        quicksort2(tab, l, p - 1);
        quicksort2(tab, p + 1, h);
    }
}

void quicksort(int *tab, int len)
{
    quicksort2(tab, 0, len - 1);
}

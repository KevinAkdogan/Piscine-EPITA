int int_sqrt(int n)
{
    int res = 1;
    int i = 0;
    if (n < 0)
    {
        return -1;
    }
    else if (n == 0)
    {
        return 0;
    }
    else
    {
        while (res <= n)
        {
            i++;
            res = i * i;
        }
        return i - 1;
    }
}

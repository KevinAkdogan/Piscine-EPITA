unsigned int digit(int n, int k)
{
    int res = 0;
    if ((n <= 0) || (k <= 0))
    {
        return 0;
    }
    while ((k - 1) > 0 && n > 0)
    {
        n = n / 10;
        k--;
        res = n % 10;
    }
    return res;
}

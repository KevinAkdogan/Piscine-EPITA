unsigned long fibo_iter(unsigned long n)
{
    unsigned long f = 0;
    unsigned long s = 1;
    unsigned long tmp;

    for (unsigned long i = 0; i < n; i++)
    {
        tmp = f + s;
        f = s;
        s = tmp;
    }
    return f;
}

unsigned int is_set(unsigned int value, unsigned char n)
{
    if (value & (1 << (n - 1)))
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

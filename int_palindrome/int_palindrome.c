int int_palindrome(int n)
{
    int tmp;
    tmp = n;
    int n_inv = 0;
    while (tmp != 0)
    {
        n_inv = n_inv * 10;
        n_inv = n_inv + tmp % 10;
        tmp = tmp / 10;
    }
    if (n == n_inv)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

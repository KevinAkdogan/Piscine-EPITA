double pi_generator(int precision)
{
    double i = precision;
    double pi;
    for (i = precision; i > 0; i--)
    {
        pi = 1.0 + i / (i * 2.0 + 1.0) * pi;
    }
    pi *= 2.0;
    return pi;
}

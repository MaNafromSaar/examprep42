unsigned int    lcm(unsigned int a, unsigned int b)
{
    int res;

    res = 1;
    if (a == 0 || b == 0)
    {
        return (0);
    }
    if (a < b)
    {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    res = a;
    while (1)
    {
        if (res % a == 0 && res % b == 0)
            return (res);
        res++;
    }
}
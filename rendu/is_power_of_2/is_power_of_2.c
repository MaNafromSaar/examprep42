int	    is_power_of_2(unsigned int n)
{
    float   x;

    x = (float)n;
    if (n < 0 || n == 0 || n > 1073741824)
        return (0); 
    while (x > 1.0)
        x = x / 2.0;
    if (x == 1.0)
        return (1);
    else
        return (0);
}
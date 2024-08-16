char	*ft_itoa(int nbr)
{
    static char s[14];
    int         i;
    int         sign;
    int         abs;

    sign = 1;
    i = 13;
    s[i] = '\0';
    i--;
    if (nbr < 0)
    {
        abs = nbr * -1;
        sign = -1;
    }
    else
    {
        abs = nbr;
    }
    if (abs == 0)
    {
        s[i] == '0';
    }
    while (abs > 0)
    {
        s[i] = abs % 10 + '0';
        abs = abs / 10;
        i--; 
    }
    if (sign == -1)
    {
        s[i] = '-';
        i--;
    }
    return (&s[i + 1]);
}
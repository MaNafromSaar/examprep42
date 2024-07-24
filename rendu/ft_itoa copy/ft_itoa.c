#include <stdlib.h>

char    res[13];

char    *ft_itoa(int nbr)
{
    int     tmp;
    int     i;

    tmp = nbr;
    if (nbr == -2147483648)
        return("-2147483648");
    if (nbr == 0)
        return("0");
    if (nbr < 0)
        nbr = -nbr;
    res[12] = '\0';
    i = 11;
    while (nbr > 0)
    {
        res[i] = '0' + nbr % 10;
        nbr = nbr / 10;
        i--;
    }
    if (tmp < 0)
    {
        res[i] = '-';
        return (&res[i]);
    }
    else
        return (&res[i + 1]);
}

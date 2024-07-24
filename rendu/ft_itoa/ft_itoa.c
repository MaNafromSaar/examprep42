#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_itoa(int nbr)
{
    char    *res;
    int     tmp;
    int     len;
    int     sign;

    len = 0;
    tmp = nbr;
    sign = 1;
    if (tmp == 0)
        return("0");
    if (tmp < 0)
    {
        tmp = -tmp;
        len++;
        sign = -1;
    }
    while (tmp != 0)
    {
        tmp = tmp / 10;
        len ++;
    }
    res = malloc(sizeof(char) * (len + 1));
    if (nbr < 0)
    {
        res[0] = '-';
    }
    res[len] = '\0';
    tmp = nbr * sign;
    while (len-- && tmp != 0)
    {
        res[len] = tmp % 10 + '0';
        tmp = tmp / 10;
    }
    return (res);
}

int main(void)
{
    char    *s;

    s = ft_itoa(-234876635);
    printf("%s\n", s);
    free(s);
    return (0);
}

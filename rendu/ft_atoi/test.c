#include <stdio.h>

int	ft_atoi(const char *str)
{
    int res;
    int sign;

    res = 0;

    sign = 1;
    while (*str)
    {
        while (*str == ' ' || *str > 8 && *str < 14)
        {
            str++;
        }
        if (*str == '-' || *str == '+')
        {
            if (*str == '-')
                sign = -1;
            str++;
        }
        while (*str >= '0' && *str <= '9')
        {
            res = res * 10 + *str - '0';
            str++;
        }
        if (!(*str >= '0' && *str <= '9' || *str == ' ' || *str > 8 && *str < 14 || *str == '-' || *str == '+'))
            break;

    }
    return (res * sign);
}

int main(void)
{
    int n;
    n = ft_atoi("test");
    printf("%i", n);
    return (0);
}
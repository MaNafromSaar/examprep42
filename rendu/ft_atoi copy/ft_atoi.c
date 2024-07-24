int	ft_atoi(const char *str)
{
    int res;
    int sign;

    sign = 1;
    res = 0;
    while (*str)
    {
        if (!(*str == ' ' || (*str > 8 && *str < 14) || *str == '-' || *str == '+' || (*str >= '0' && *str <= '9')))
            return (res * sign);
        if (*str == ' ' || (*str > 8 && *str < 14))
            str++;
        if (*str == '-' || *str == '+')
            if (*str == '-')
            {
                sign *= -1;
                str++;
            }
            else
                str++;
        while (*str >= '0' && *str <= '9' && res < __INT32_MAX__ / 10)
        {
            res = res * 10 + (*str - '0');
            str++;
        }
    }
    res = res * sign;
    return (res);
}
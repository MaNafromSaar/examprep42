int	ft_atoi_base(const char *str, int str_base)
{
    int result;
    int sign;
    char *base = "0123456789ABCDEF";
    char used_base[17];
    int i;
    int tmp;

    tmp = 0;
    i = 0;
    sign = 1;
    result = 0;
    while (i < str_base)
    {
        used_base[i] = base[i];
        i++;
    }
    used_base[i] = '\0';
    i = 0;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str)
    {
        i = 0;
        tmp = -1;
        while (used_base[i])
        {
            if (*str == used_base[i] || *str == used_base[i] + 32)
            {
                tmp = i;
                break;
            }
            i++;
        }
        result = result * str_base + tmp;
        str++;
    }
    return (result * sign);
}
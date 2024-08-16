#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
    char *s;
    int result;
    int sign;
    char *base = "0123456789ABCDEF";
    char used_base[17];
    int i;
    int tmp;

    tmp = 0;
    s = (char *)str;
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
    s = (char *)str;
    if (*s == '-')
    {
        sign = -1;
        s++;
    }
    while (*s)
    {
        i = 0;
        tmp = -1;
        while (used_base[i])
        {
            if (*s == used_base[i] || *s == used_base[i] + 32)
            {
                tmp = i;
                break;
            }
            i++;
        }
        result = result * str_base + tmp;
        s++;
    }
    return (result * sign);
}

int main()
{
    char *str = "ff";
    int str_base = 16;
    printf("%d\n", ft_atoi_base(str, str_base));
    return 0;
}
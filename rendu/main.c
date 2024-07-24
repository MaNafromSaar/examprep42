/*#include <stdio.h>

int	ft_atoi(const char *str)
{
	int sign;
	int res;
    const char *tmp;
    int pow;

	sign = 1;
	res = 0;
    pow = 1;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
    tmp =str;
	while (*tmp >= '0' && *tmp <= '9')
		tmp++;
    tmp--;
	while (tmp >= str)
	{
		res = res + (pow * (*tmp - '0'));
        tmp--;
        pow *= 10;
	}
	return (res * sign);
}*/

int	main(void)
{
	/*char	*str;
    int     num;

	str = "-+-42+32";
	num = ft_atoi(str);
    printf("%d\n", num);*/
    
	return (0);
}

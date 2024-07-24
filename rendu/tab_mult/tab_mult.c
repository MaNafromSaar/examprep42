#include <stdio.h>
#include <stdlib.h>

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
}

int main (int argc,const char *argv[])
{
    int i;
    int num;

    i = 1;
    if (argc != 2)
    {
        printf("\n");
        exit (0);
    }
    num = ft_atoi(argv[1]);
    while (i < 10 && !(num > (2147483647 / 9)))
    {
        printf("%d x %d = %d\n", i, num, i * num);
        i++;
    }
}

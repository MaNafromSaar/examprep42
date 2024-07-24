/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:07:55 by root              #+#    #+#             */
/*   Updated: 2024/07/17 20:31:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

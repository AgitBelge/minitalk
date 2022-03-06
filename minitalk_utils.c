/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelge <abelge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 01:17:31 by abelge            #+#    #+#             */
/*   Updated: 2022/03/06 05:04:14 by abelge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *s)
{
	int				nm;
	long long int	tmp;

	nm = 1;
	tmp = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t' || *s == '\v'
		|| *s == '\f' || *s == '\r')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			nm = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		tmp = (tmp * 10) + (*s - '0');
		s++;
		if (tmp * nm > 2147483647)
			return (-1);
		if (tmp * nm < -2147483648)
			return (0);
	}
	return (tmp * nm);
}

int	ft_putstr(char *s)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i += write(1, &s[x++], 1);
	return (i);
}

int	ft_putnbr_osman(unsigned int n)
{
	int				cnt;
	unsigned int	i;
	char			str[10];

	cnt = 0;
	i = 0;
	if (n == 0)
		cnt += ft_putchar('0');
	while (n)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i--)
		cnt += ft_putchar(str[i]);
	return (cnt);
}

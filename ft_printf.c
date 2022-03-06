/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelge <abelge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 04:52:34 by abelge            #+#    #+#             */
/*   Updated: 2022/03/06 06:57:37 by abelge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_osman(va_list list, char str, int a)
{
	if (str == 's')
		a = ft_putstr(va_arg(list, char *));
	else if (str == 'u')
		a = ft_putnbr_osman(va_arg(list, unsigned int));
	else if (str == 'd')
		a = ft_putnbr(va_arg(list, int));
	return (a);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		a;
	va_list	list;

	a = 0;
	va_start(list, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
			a += ft_osman(list, s[++i], a);
		else
			a += write(1, &s[i], 1);
		i++;
	}
	va_end(list);
	return (a);
}

int	ft_putchar(int a)
{
	int	i;

	i = 0;
	i += write(1, &a, 1);
	return (i);
}

int	ft_putnbr(int nb)
{
	unsigned int	i;
	int				cnt;

	cnt = 0;
	i = 0;
	if (nb < 0)
	{
		cnt += ft_putchar('-');
		i = -nb;
	}
	else
		i = nb;
	if (i > 9)
	{
		cnt += ft_putnbr(i / 10);
		cnt += ft_putchar((i % 10) + 48);
	}
	else
		cnt += ft_putchar(i + 48);
	return (cnt);
}

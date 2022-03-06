/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelge <abelge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 01:03:23 by abelge            #+#    #+#             */
/*   Updated: 2022/03/06 07:16:13 by abelge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	farketmez(pid_t pd, int c)
{
	int	nbr;
	int	bit_nbr;

	nbr = 8;
	bit_nbr = 128;
	while (nbr--)
	{
		if (c / bit_nbr)
		{	
			c = c - bit_nbr;
			kill(pd, SIGUSR1);
		}
		else
			kill(pd, SIGUSR2);
		usleep(100);
		bit_nbr /= 2;
	}
}

int	main(int i, char **str)
{
	int		idx;
	int		p;
	char	*s;

	idx = 0;
	if (i != 3)
	{
		printf("%s", "HATA!!!");
		return (0);
	}
	else
	{
		s = str[2];
		p = ft_atoi(str[1]);
		farketmez(p, '\n');
		while (s[idx])
		{
			farketmez(p, s[idx]);
			idx++;
		}
	}
}
//void	vekapisi(pid_t pd, int c)
//{
//	int i;
//	i = 7;
//	while (i >= 0)
//	{
//		if (c & (1 << i))
//			kill(pd,SIGUSR1);
//		else
//			kill(pd, SIGURG2);
//	i--;
//	}
//}

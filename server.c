/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelge <abelge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 01:03:39 by abelge            #+#    #+#             */
/*   Updated: 2022/03/06 06:56:56 by abelge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h" 

void	osman(int i)
{
	static char	t = 0;
	static int	r = 7;

	t += i << r;
	if (r == 0)
	{
		write(1, &t, 1);
		t = 0;
		r = 7;
	}
	else
		r--;
}

void	convert_ft(int i)
{
	if (i == SIGUSR1)
		osman(1);
	else if (i == SIGUSR2)
		osman(0);
}

int	main(void)
{
	ft_printf("%d", getpid());
	signal(SIGUSR1, convert_ft);
	signal(SIGUSR2, convert_ft);
	while (1)
		pause();
}

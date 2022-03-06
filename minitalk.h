/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelge <abelge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 01:03:54 by abelge            #+#    #+#             */
/*   Updated: 2022/03/06 05:34:06 by abelge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include  <unistd.h>
# include  <stdio.h>
# include  <signal.h>
# include <stdarg.h>

int		ft_atoi(const char *s);
void	farketmez(pid_t pd, int c);
void	osman(int i);
void	convert_ft(int i);
int		ft_putstr(char *s);
int		ft_putnbr_osman(unsigned int n);
int		ft_osman(va_list list, char str, int a);
int		ft_printf(const char *s, ...);
int		ft_putchar(int a);
int		ft_putnbr(int nb);
#endif

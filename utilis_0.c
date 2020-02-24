/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilis_0.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 14:09:45 by qli            #+#    #+#                */
/*   Updated: 2020/02/20 18:21:17 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int		ft_check_specifier(char *fmt, int i)
{
	if (fmt[i] == 'c' || fmt[i] == 's' || fmt[i] == 'p'
	|| fmt[i] == 'd' || fmt[i] == 'i' || fmt[i] == 'u'
	|| fmt[i] == 'x' || fmt[i] == 'X' || fmt[i] == '%')
		return (1);
	return (0);
}

int		ft_digit_len(int d)
{
	int		i;
	int		neg;

	i = 0;
	neg = 1;
	if (d == 0)
		i = 1;
	if (d == -2147483648)
	{
		i = 11;
		return (i);
	}
	if (d < 0)
	{
		i++;
		neg = neg * -1;
		d = d * -1;
	}
	while (d > 0)
	{
		d = d / 10;
		i++;
	}
	return (i);
}

int		ft_digit_u(unsigned u)
{
	int		i;

	i = 0;
	if (u == 0)
		i = 1;
	while (u > 0)
	{
		u = u / 10;
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex_convert_4.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 11:05:10 by qli            #+#    #+#                */
/*   Updated: 2020/02/19 13:42:26 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	negative width -> minus flag + positive width
**	negative precision with 0 value -> print 0
**	negative precision -> 0 (leave a signal for zero flag)
**	minus flag + zero flag -> minus flag
**	len > width && precision -> no conversion needed
*/

static int	ft_input_check(t_input *input, int u)
{
	int	len;

	len = ft_digit_hex(u);
	if (input->width < 0)
	{
		input->width = input->width * -1;
		input->flag = 1;
		input->minus_flag = 1;
	}
	if (input->width == 0 && input->precision_present == 1
	&& input->precision < 0 && u == 0)
		return (1);
	if (input->precision < 0)
	{
		input->precision = 0;
		if (input->flag == 1)
			input->precision_present = 0;
	}
	if (input->minus_flag == 1 && input->zero_flag == 1)
		input->zero_flag = 0;
	if (input->precision_present == 1 && input->precision == 0 && u == 0)
		return (2);
	if (input->width <= len && input->precision <= len)
		return (1);
	return (0);
}

/*
**	1) when precision is bigger than width -> print ' '
**	2) when width > precision -> print ' ' (width - precision/len)
**	3) print '0' if precision > len
**	4) print integer
*/

static void	ft_no_flag(t_input *input, t_print *print, unsigned int *u, int len)
{
	int	count;

	count = 0;
	if (input->precision >= input->width)
	{
		count = input->precision - len;
		ft_set_pad(input, print, count, 0);
	}
	else if (input->width > input->precision)
	{
		ft_set_count_u(input, &count, len);
		if (input->precision_present == 1 && input->precision == 0 && *u == 0)
		{
			count++;
			ft_set_pad(input, print, count, 1);
			return ;
		}
		if (count > 0)
			ft_set_pad(input, print, count, 1);
		count = input->precision - len;
		if (count > 0)
			ft_set_pad(input, print, count, 0);
	}
	ft_putnbr_hex(*u, input);
}

/*
**	1) width > precision:
**	   print '0' if precision > len, print integer, print ' '
**	2) width <= preccision
**	   print '0' (precision - len), print integer
*/

static void	ft_minus(t_input *input, t_print *print, unsigned int *u, int len)
{
	int	count;

	count = 0;
	if (input->width > input->precision)
	{
		count = input->precision - len;
		if (count > 0)
			ft_set_pad(input, print, count, 0);
		ft_putnbr_hex(*u, input);
		ft_set_count_u(input, &count, len);
		if (count > 0)
			ft_set_pad(input, print, count, 1);
	}
	else if (input->width <= input->precision)
	{
		count = input->precision - len;
		ft_set_pad(input, print, count, 0);
		ft_putnbr_hex(*u, input);
	}
}

/*
**	1) only width -> print '0' & integer
**	2) width & precision -> print ' ', integer & '0'
**	3) width & negative precision == width & precision not present
*/

static void	ft_zero(t_input *input, t_print *print, unsigned int *u, int len)
{
	int	count;

	count = 0;
	if (input->width > 0 && input->precision_present == 0)
	{
		count = input->width - len;
		if (count > 0)
			ft_set_pad(input, print, count, 0);
	}
	else if (input->width > input->precision && input->precision_present == 1)
	{
		ft_set_count_u(input, &count, len);
		if (count > 0)
			ft_set_pad(input, print, count, 1);
	}
	count = input->precision - len;
	if (count > 0)
		ft_set_pad(input, print, count, 0);
	ft_putnbr_hex(*u, input);
}

/*
**	check input: negative width/precision, double flags, no conversion, %0.0u, 0
**	conversion needed: no flag, minus flag, zero flag
*/

int			ft_hex_convert(t_input *input, t_print *print, unsigned int u)
{
	int	len;

	len = ft_digit_hex(u);
	if (ft_input_check(input, u) == 1)
		ft_putnbr_hex(u, input);
	else if (ft_input_check(input, u) == 2)
		ft_set_pad(input, print, input->width, 1);
	else if (ft_input_check(input, u) == 0)
	{
		if (input->flag == 0)
			ft_no_flag(input, print, &u, len);
		else if (input->minus_flag == 1)
			ft_minus(input, print, &u, len);
		else if (input->zero_flag == 1)
			ft_zero(input, print, &u, len);
	}
	return (0);
}

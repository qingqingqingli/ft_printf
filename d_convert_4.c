/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   d_convert_4.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 10:57:22 by qli            #+#    #+#                */
/*   Updated: 2020/02/18 16:59:54 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	negative width -> minus flag + positive width
**	negative precision -> 0
**	minus flag + zero flag -> minus flag
**	len > width && precision -> no conversion needed
*/

static int	ft_input_check(t_input *input, int d)
{
	int	len;

	len = ft_digit_len(d);
	if (input->width < 0)
	{
		input->width = input->width * -1;
		input->flag = 1;
		input->minus_flag = 1;
	}
	if (input->width == 0 && input->precision_present == 1
	&& input->precision < 0 && d == 0)
		return (1);
	if (input->precision < 0)
		input->precision = 0;
	if (input->minus_flag == 1 && input->zero_flag == 1)
		input->zero_flag = 0;
	if (input->width == 0 && input->precision_present == 1
	&& input->precision == 0 && d == 0)
		return (2);
	if (d > 0 && input->width <= len && input->precision <= len)
		return (1);
	if (d < 0 && input->width <= len && input->precision <= len - 1)
		return (1);
	return (0);
}

/*
**	1) print ' ' only when width > len && width > precision
**	2) print '-' if negative integer (positive)
**	3) print '0' if precision > len (negative +1)
**	4) print integer
*/

static void	ft_no_flag(t_input *input, t_print *print, int *d, int len)
{
	int count;

	count = 0;
	ft_set_count(input, *d, &count, len);
	if (count > 0)
		ft_set_pad(input, print, count, 1);
	count = input->precision - len;
	*d < 0 ? count++ : count;
	if (count > 0)
	{
		if (*d < 0)
			ft_con_minus(input, d, &count, 0);
		ft_set_pad(input, print, count, 0);
	}
	if (*d == 0 && input->precision_present == 1
	&& input->precision == 0)
	{
		ft_putchar(' ', input);
		return ;
	}
	ft_putnbr(*d, input);
}

/*
**	1) print '-' if negative integer
**	2) print '0' if precision > len (negative +1)
**	3) print integer (positive)
**	4) print ' ' when width > len && width > precision
*/

static void	ft_minus_flag(t_input *input, t_print *print, int *d, int len)
{
	int neg;
	int count;

	neg = 0;
	count = input->precision - len;
	if (*d < 0)
	{
		ft_con_minus(input, d, &count, 1);
		neg = -1;
	}
	if (count > 0)
		ft_set_pad(input, print, count, 0);
	if (*d == 0 && input->precision_present == 1
	&& input->precision == 0)
	{
		ft_set_count(input, neg, &count, len);
		count++;
	}
	else
	{
		ft_putnbr(*d, input);
		ft_set_count(input, neg, &count, len);
	}
	if (count > 0)
		ft_set_pad(input, print, count, 1);
}

/*
**	1) when width && precision: -> same procedure as no flag
**	2) when no width or no precision -> '-', '0' & (positive) integer
*/

static void	ft_zero_flag(t_input *input, t_print *print, int *d, int len)
{
	int count;

	count = 0;
	if (input->width > 0 && input->precision_present == 1)
		ft_no_flag(input, print, d, len);
	else
	{
		input->width ? (count = input->width - len) :
		(count = input->precision - len);
		if (*d < 0)
			input->precision_present == 1 ?
			ft_con_minus(input, d, &count, 1) :
			ft_con_minus(input, d, &count, 0);
		ft_set_pad(input, print, count, 0);
		ft_putnbr(*d, input);
	}
}

/*
**	check input: negative width/precision, double flags, no conversion, %0.0d, 0
**	conversion needed: no flag, minus flag, zero flag
*/

int			ft_d_convert(t_input *input, t_print *print, int d)
{
	int	len;

	len = ft_digit_len(d);
	if (ft_input_check(input, d) == 1)
	{
		if (d == INT_MIN)
			ft_putchar('-', input);
		ft_putnbr(d, input);
	}
	else if (ft_input_check(input, d) == 0)
	{
		if (input->flag == 0)
			ft_no_flag(input, print, &d, len);
		else if (input->minus_flag == 1)
			ft_minus_flag(input, print, &d, len);
		else if (input->zero_flag == 1)
			ft_zero_flag(input, print, &d, len);
	}
	else if (ft_input_check(input, d) == 2)
		return (0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_convert_4.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 16:09:25 by qli            #+#    #+#                */
/*   Updated: 2020/02/20 18:27:30 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_input_check(t_input *input)
{
	if (input->width < 0)
	{
		input->width = input->width * -1;
		input->flag = 1;
		input->minus_flag = 1;
	}
	if (input->minus_flag == 1 && input->zero_flag == 1)
		input->zero_flag = 0;
	if (input->precision < 0)
	{
		input->precision = 0;
		input->precision_present = 0;
	}
	return (0);
}

static void	ft_minus_flag(t_input *input, t_print *print, char *s, int len)
{
	int	count;

	count = 0;
	if (input->precision_present == 1)
	{
		(len > input->precision) ?
		(count = input->precision) :
		(count = len);
		if (count > 0)
			ft_print_str(s, count, input);
		(input->precision > len) ?
		(count = input->width - len) :
		(count = input->width - input->precision);
		if (count > 0)
			ft_set_pad(input, print, count, 1);
	}
	else
	{
		ft_print_str(s, len, input);
		count = input->width - len;
		if (count > 0)
			ft_set_pad(input, print, count, 1);
	}
}

static void	ft_no_flag(t_input *input, t_print *print, char *s, int len)
{
	int	count;

	count = 0;
	if (input->precision_present == 0)
	{
		count = input->width - len;
		if (count > 0)
			ft_set_pad(input, print, count, 1);
		ft_print_str(s, len, input);
		return ;
	}
	(input->precision > len) ?
	(count = input->width - len) :
	(count = input->width - input->precision);
	if (count > 0)
		ft_set_pad(input, print, count, 1);
	(len > input->precision) ?
	(count = input->precision) :
	(count = len);
	if (count > 0)
		ft_print_str(s, count, input);
}

static void	ft_zero_flag(t_input *input, t_print *print, char *s, int len)
{
	int	count;

	count = 0;
	if (input->precision_present == 0)
	{
		count = input->width - len;
		if (count > 0)
			ft_set_pad(input, print, count, 0);
		ft_print_str(s, len, input);
	}
}

int			ft_str_convert(t_input *input, t_print *print, char *s)
{
	int	len;

	if (ft_strncmp(s, "(null)", 6) == 0)
		s = "(null)";
	ft_input_check(input);
	len = ft_strlen(s);
	ft_input_check(input);
	if (input->flag == 0)
		ft_no_flag(input, print, s, len);
	if (input->minus_flag == 1)
		ft_minus_flag(input, print, s, len);
	if (input->zero_flag == 1)
		ft_zero_flag(input, print, s, len);
	return (0);
}

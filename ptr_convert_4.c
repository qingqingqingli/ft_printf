/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ptr_convert_4.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 15:03:24 by qli            #+#    #+#                */
/*   Updated: 2020/02/20 17:57:07 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_input_check(t_input *input)
{
	if (input->width < 0)
	{
		input->width = input->width * -1;
		input->flag = 1;
		input->minus_flag = 1;
	}
}

static void	ft_print_p(long long int p, t_input *input, t_print *print)
{
	int	count;
	int	len;

	len = ft_len_hex(p);
	count = 0;
	ft_putchar('0', input);
	ft_putchar('x', input);
	if (input->precision_present == 1 && input->precision > 0)
	{
		count = input->precision - len;
		if (count > 0)
			ft_set_pad(input, print, count, 0);
	}
	ft_putnbr_hex_lli(p, input);
}

static void	ft_noflag(t_input *input, t_print *print, long long int p, int len)
{
	int	count;

	count = 0;
	if (input->precision_present == 1 && input->precision == 0 && p == 0)
	{
		count = input->width - 2;
		if (count > 0)
			ft_set_pad(input, print, count, 1);
		ft_putchar('0', input);
		ft_putchar('x', input);
		return ;
	}
	count = input->width - len;
	if (count > 0)
		ft_set_pad(input, print, count, 1);
	ft_print_p(p, input, print);
}

static void	ft_minus(t_input *input, t_print *print, long long int p, int len)
{
	int	count;

	count = input->width - len;
	ft_print_p(p, input, print);
	if (count > 0)
		ft_set_pad(input, print, count, 1);
}

int			ft_ptr_convert(t_input *input, t_print *print, long long int p)
{
	int	len;

	len = ft_len_hex(p) + 2;
	ft_input_check(input);
	if (input->flag == 0)
		ft_noflag(input, print, p, len);
	else if (input->minus_flag == 1)
		ft_minus(input, print, p, len);
	return (0);
}

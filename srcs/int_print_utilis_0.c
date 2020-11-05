/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_print_utilis_0.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 10:57:43 by qli           #+#    #+#                 */
/*   Updated: 2020/11/05 16:54:50 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_set_count_u(t_input *input, int *count, int len)
{
	(input->precision > len) ?
	(*count = input->width - input->precision) :
	(*count = input->width - len);
}

/*
**	set count based on two criterias:
**	negative/positive integer: width include '-', precision does not
**	precision vs. len: to calculate required padding
*/

void	ft_set_count(t_input *input, int d, int *count, int len)
{
	if (d >= 0)
		(input->precision > len) ?
		(*count = input->width - input->precision) :
		(*count = input->width - len);
	else if (d < 0)
		(input->precision >= len) ?
		(*count = input->width - input->precision - 1) :
		(*count = input->width - len);
}

/*
**	print '-'
**	convert negative to positive
*/

void	ft_con_minus(t_input *input, int *d, int *count, int signal)
{
	if (signal == 1)
		*count = *count + 1;
	ft_putchar('-', input);
	*d = *d * -1;
}

/*
**	print 'count' amount of ' ' or '0'
*/

void	ft_set_pad(t_input *input, t_print *print, int count, int pad)
{
	print->count = count;
	if (pad == 0)
		print->zero_padding = 1;
	else if (pad == 1)
		print->space_padding = 1;
	while (print->count > 0)
	{
		if (print->space_padding == 1)
			ft_putchar(' ', input);
		if (print->zero_padding == 1)
			ft_putchar('0', input);
		print->count--;
	}
	ft_reset_convert_struct(print);
}

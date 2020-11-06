/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_convert_3.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:43:48 by qli           #+#    #+#                 */
/*   Updated: 2020/11/06 19:50:51 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_reset_convert_struct(t_print *print)
{
	print->count = 0;
	print->space_padding = 0;
	print->zero_padding = 0;
}

static void	ft_choose_specifier(t_input *input, t_print *print, va_list ap)
{
	char *str;

	if (input->specifier == 'd' || input->specifier == 'i')
		ft_d_convert(input, print, va_arg(ap, int));
	else if (input->specifier == 'u')
		ft_u_convert(input, print, va_arg(ap, unsigned int));
	else if (input->specifier == 'x' || input->specifier == 'X')
		ft_hex_convert(input, print, va_arg(ap, unsigned int));
	else if (input->specifier == 'c')
		ft_char_convert(input, print, va_arg(ap, int));
	else if (input->specifier == 's')
	{
		str = va_arg(ap, char *);
		if (str == NULL)
			ft_str_convert(input, print, "(null)");
		else
			ft_str_convert(input, print, str);
	}
	else if (input->specifier == '%')
		ft_percent_convert(input, print);
	else if (input->specifier == 'p')
		ft_ptr_convert(input, print, va_arg(ap, long long int));
}

int			ft_input_convert(t_input *input, va_list ap)
{
	t_print		print;

	ft_reset_convert_struct(&print);
	ft_choose_specifier(input, &print, ap);
	return (0);
}

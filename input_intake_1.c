/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_intake_1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 16:17:13 by qli            #+#    #+#                */
/*   Updated: 2020/02/20 18:25:23 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_struct_reset(t_input *input)
{
	input->flag = 0;
	input->minus_flag = 0;
	input->zero_flag = 0;
	input->width = 0;
	input->precision_present = 0;
	input->precision = 0;
	input->specifier_present = 0;
	input->specifier = 0;
}

static void	ft_per_convert(char *fmt, t_input *input, int *i)
{
	ft_putchar('%', input);
	*i = *i + 1;
	while (fmt[*i] != '\0' && fmt[*i] != '%')
	{
		ft_putchar(fmt[*i], input);
		*i = *i + 1;
	}
}

static int	ft_process_input(char *fmt, t_input *input, va_list ap)
{
	int i;

	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == '%')
				ft_per_convert(fmt, input, &i);
			else
			{
				ft_struct_reset(input);
				ft_input_parse(fmt, &i, input, ap);
				if (input->specifier_present == 1)
					ft_input_convert(input, ap);
			}
		}
		if (fmt[i] != '%' && fmt[i] != '\0')
		{
			ft_putchar(fmt[i], input);
			i++;
		}
	}
	return (0);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_input		input;

	va_start(ap, fmt);
	ft_struct_reset(&input);
	input.return_val = 0;
	if (ft_process_input((char *)fmt, &input, ap) == -1)
		return (-1);
	va_end(ap);
	return (input.return_val);
}

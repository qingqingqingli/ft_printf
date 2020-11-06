/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parse_2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 16:24:00 by qli           #+#    #+#                 */
/*   Updated: 2020/11/05 16:54:50 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_set_specifier(char *fmt, int i, t_input *input)
{
	if (fmt[i] == 'c')
		input->specifier = 'c';
	if (fmt[i] == 's')
		input->specifier = 's';
	if (fmt[i] == 'p')
		input->specifier = 'p';
	if (fmt[i] == 'd')
		input->specifier = 'd';
	if (fmt[i] == 'i')
		input->specifier = 'i';
	if (fmt[i] == 'u')
		input->specifier = 'u';
	if (fmt[i] == 'x')
		input->specifier = 'x';
	if (fmt[i] == 'X')
		input->specifier = 'X';
	if (fmt[i] == '%')
		input->specifier = '%';
}

static int	ft_check_precision(char *fmt, int *i, t_input *input, va_list ap)
{
	if (fmt[*i] == '.')
	{
		*i = *i + 1;
		input->precision_present = 1;
		if (fmt[*i] != '\0' && fmt[*i] == '*')
		{
			input->precision = va_arg(ap, int);
			*i = *i + 1;
		}
		else if (fmt[*i] != '\0' && ft_isdigit(fmt[*i]) == 1)
		{
			while (fmt[*i] != '\0' && ft_isdigit(fmt[*i]) == 1)
			{
				input->precision = (input->precision * 10) + fmt[*i] - '0';
				*i = *i + 1;
			}
		}
	}
	return (0);
}

static int	ft_check_width(char *fmt, int *i, t_input *input, va_list ap)
{
	if (fmt[*i] != '\0' && fmt[*i] == '*')
	{
		input->width = va_arg(ap, int);
		*i = *i + 1;
	}
	if (fmt[*i] != '\0' && fmt[*i] != '0' && ft_isdigit(fmt[*i]) == 1)
	{
		while (ft_isdigit(fmt[*i]) == 1 && fmt[*i] != '\0')
		{
			input->width = (input->width * 10) + fmt[*i] - '0';
			*i = *i + 1;
		}
	}
	return (0);
}

static int	ft_check_flags(char *fmt, int *i, t_input *input)
{
	if (fmt[*i] == '-')
	{
		input->flag = 1;
		input->minus_flag = 1;
		*i = *i + 1;
	}
	else if (fmt[*i] == '0')
	{
		input->flag = 1;
		input->zero_flag = 1;
		*i = *i + 1;
	}
	else if (fmt[*i] != '-' && fmt[*i] != '.' && fmt[*i] != '*' &&
	ft_isdigit(fmt[*i]) == 0)
		*i = *i + 1;
	return (0);
}

int			ft_input_parse(char *fmt, int *i, t_input *input, va_list ap)
{
	while (ft_check_specifier(fmt, *i) == 0 && fmt[*i] != '\0')
	{
		ft_check_flags(fmt, i, input);
		ft_check_width(fmt, i, input, ap);
		ft_check_precision(fmt, i, input, ap);
	}
	if (ft_check_specifier(fmt, *i) == 1 && fmt[*i] != '\0')
	{
		input->specifier_present = 1;
		ft_set_specifier(fmt, *i, input);
		*i = *i + 1;
	}
	return (0);
}

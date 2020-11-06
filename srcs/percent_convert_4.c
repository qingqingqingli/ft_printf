/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   percent_convert_4.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 14:20:52 by qli           #+#    #+#                 */
/*   Updated: 2020/11/06 19:50:51 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
	return (0);
}

static void	ft_no_flag(t_input *input, t_print *print, int c)
{
	int	count;

	count = input->width - 1;
	if (count > 0)
		ft_set_pad(input, print, count, 1);
	ft_putchar(c, input);
}

static void	ft_minus_flag(t_input *input, t_print *print, int c)
{
	int	count;

	count = input->width - 1;
	ft_putchar(c, input);
	if (count > 0)
		ft_set_pad(input, print, count, 1);
}

static void	ft_zero_flag(t_input *input, t_print *print, int c)
{
	int	count;

	count = input->width - 1;
	if (count > 0)
		ft_set_pad(input, print, count, 0);
	ft_putchar(c, input);
}

int			ft_percent_convert(t_input *input, t_print *print)
{
	ft_input_check(input);
	if (input->flag == 0)
		ft_no_flag(input, print, '%');
	else if (input->minus_flag == 1)
		ft_minus_flag(input, print, '%');
	else if (input->zero_flag == 1)
		ft_zero_flag(input, print, '%');
	return (0);
}

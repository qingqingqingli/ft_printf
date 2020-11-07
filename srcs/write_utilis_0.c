/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_utilis_0.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 16:20:11 by qli           #+#    #+#                 */
/*   Updated: 2020/11/07 11:46:04 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putchar(char c, t_input *input)
{
	int		output;

	output = write(1, &c, 1);
	if (output == -1 || input->return_val == -1)
		input->return_val = -1;
	else
		input->return_val++;
	return (0);
}

void	ft_putnbr(int n, t_input *input)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putchar('2', input);
			n = 147483648;
		}
		else
		{
			ft_putchar('-', input);
			n = n * -1;
		}
	}
	if (n >= 10)
		ft_putnbr(n / 10, input);
	ft_putchar('0' + (n % 10), input);
}

void	ft_putnbr_unsigned(unsigned int u, t_input *input)
{
	if (u >= 10)
		ft_putnbr(u / 10, input);
	ft_putchar('0' + (u % 10), input);
}

void	ft_putnbr_hex(unsigned int u, t_input *input)
{
	if (u >= 16)
		ft_putnbr_hex(u / 16, input);
	if ((u % 16) >= 0 && (u % 16) <= 9)
		ft_putchar('0' + (u % 16), input);
	else if ((u % 16) >= 10 && (u % 16) < 16)
	{
		if (input->specifier == 'x')
			ft_putchar('a' + (u % 16 - 10), input);
		if (input->specifier == 'X')
			ft_putchar('A' + (u % 16 - 10), input);
	}
}

void	ft_putnbr_hex_lli(long long int p, t_input *input)
{
	if (p >= 16)
		ft_putnbr_hex_lli(p / 16, input);
	if ((p % 16) >= 0 && (p % 16) <= 9)
		ft_putchar('0' + (p % 16), input);
	else if ((p % 16) >= 10 && (p % 16) < 16)
		ft_putchar('a' + (p % 16 - 10), input);
}

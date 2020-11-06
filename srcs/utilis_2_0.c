/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilis_2_0.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 18:20:56 by qli           #+#    #+#                 */
/*   Updated: 2020/11/05 16:54:50 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_len_hex(long long int p)
{
	int		i;

	i = 0;
	if (p == 0)
		i = 1;
	while (p > 0)
	{
		p = p / 16;
		i++;
	}
	return (i);
}

int		ft_digit_hex(unsigned u)
{
	int		i;

	i = 1;
	while (u >= 16)
	{
		u = u / 16;
		i++;
	}
	return (i);
}

size_t	ft_strlen(char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] & i < n - 1)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_print_str(char *s, int count, t_input *input)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && i < count)
	{
		ft_putchar(s[i], input);
		i++;
	}
}

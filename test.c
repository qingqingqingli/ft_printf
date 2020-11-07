/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 19:24:55 by qli           #+#    #+#                 */
/*   Updated: 2020/11/07 10:31:24 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

void	basic_char_test(void)
{
	char c;

	c = 'a';
	printf("\033[0;32m""\n--char test--""\033[0m""\n");
	printf("[%d]\n", ft_printf("%c", c));
	printf("[%d]\n", printf("%c", c));
	printf("\033[0;33m""-----------------""\033[0m""\n");
	printf("[%d]\n", ft_printf("%-5c", c));
	printf("[%d]\n", printf("%-5c", c));
	printf("\033[0;33m""-----------------""\033[0m""\n");
	printf("[%d]\n", ft_printf("%-10c", c));
	printf("[%d]\n", printf("%-10c", c));
	printf("\033[0;33m""-----------------""\033[0m""\n");
	printf("[%d]\n", ft_printf("%*c", -10, c));
	printf("[%d]\n", printf("%*c", -10, c));
	printf("\033[0;33m""-----------------""\033[0m""\n");
}

int		main(void)
{
	basic_char_test();
	return (0);
}

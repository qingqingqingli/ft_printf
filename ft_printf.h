/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 16:16:13 by qli            #+#    #+#                */
/*   Updated: 2020/02/21 09:23:33 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef	struct	s_input
{
	int			flag;
	int			minus_flag;
	int			zero_flag;
	int			width;
	int			precision_present;
	int			precision;
	int			specifier_present;
	char		specifier;
	int			return_val;
}				t_input;

typedef	struct	s_print
{
	int			count;
	int			zero_padding;
	int			space_padding;
}				t_print;

int				ft_printf(const char *fmt, ...);
int				ft_putchar(char c, t_input *input);
void			ft_struct_reset(t_input *input);
int				ft_check_specifier(char *fmt, int i);
int				ft_input_parse(char *fmt, int *i, t_input *input, va_list ap);
int				ft_isdigit(int c);
int				ft_input_convert(t_input *input, va_list ap);
int				ft_digit_len(int d);
void			ft_reset_convert_struct(t_print *print);
void			ft_putnbr(int n, t_input *input);
int				ft_d_convert(t_input *input, t_print *print, int d);
void			ft_print(t_input input);
void			ft_printf_struct(t_print print);
int				ft_int_print(t_input *input, t_print *print, int d, int neg);
void			ft_print_int_struct(t_input *input, t_print *print);
void			ft_set_pad(t_input *input, t_print *print, int count, int pad);
void			ft_con_minus(t_input *input, int *d, int *count, int signal);
int				ft_u_convert(t_input *input, t_print *print, unsigned int u);
void			ft_putnbr_unsigned(unsigned int n, t_input *input);
int				ft_digit_u(unsigned d);
void			ft_set_count_u(t_input *input, int *count, int len);
void			ft_set_count(t_input *input, int d, int *count, int len);
int				ft_d_convert(t_input *input, t_print *print, int d);
int				ft_digit_hex(unsigned u);
void			ft_putnbr_hex(unsigned int u, t_input *input);
int				ft_hex_convert(t_input *input, t_print *print, unsigned int u);
int				ft_char_convert(t_input *input, t_print *print, int c);
size_t			ft_strlen(char *s);
int				ft_str_convert(t_input *input, t_print *print, char *s);
int				ft_strncmp(char *s1, char *s2, size_t n);
int				ft_percent_convert(t_input *input, t_print *print);
int				ft_ptr_convert(t_input *input, t_print *print, long long int p);
int				ft_len_hex(long long int p);
void			ft_putnbr_hex_lli(long long int p, t_input *input);
void			ft_print_str(char *s, int count, t_input *input);

#endif

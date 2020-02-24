# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qli <qli@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/30 16:15:43 by qli            #+#    #+#                 #
#    Updated: 2020/02/21 09:21:42 by qli           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	input_intake_1.c\
		write_utilis_0.c\
		utilis_0.c\
		input_parse_2.c\
		input_convert_3.c\
		d_convert_4.c\
		int_print_utilis_0.c\
		u_convert_4.c\
		hex_convert_4.c\
		char_convert_4.c\
		str_convert_4.c\
		percent_convert_4.c\
		ptr_convert_4.c\
		utilis_2_0.c

SRC_O = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC_O)
	@echo "creating libftprint.a"
	@ar rc $(NAME) $(SRC_O)
	@ranlib $(NAME)

clean:
	@rm -f $(SRC_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

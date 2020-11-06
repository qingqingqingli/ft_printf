# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qli <qli@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/30 16:15:43 by qli           #+#    #+#                  #
#    Updated: 2020/11/06 19:49:13 by qli           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	srcs/input_intake_1.c\
		srcs/write_utilis_0.c\
		srcs/utilis_0.c\
		srcs/input_parse_2.c\
		srcs/input_convert_3.c\
		srcs/d_convert_4.c\
		srcs/int_print_utilis_0.c\
		srcs/u_convert_4.c\
		srcs/hex_convert_4.c\
		srcs/char_convert_4.c\
		srcs/str_convert_4.c\
		srcs/percent_convert_4.c\
		srcs/ptr_convert_4.c\
		srcs/utilis_2_0.c

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

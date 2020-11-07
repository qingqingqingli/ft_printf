# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qli <qli@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/30 16:15:43 by qli           #+#    #+#                  #
#    Updated: 2020/11/07 11:48:13 by qli           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= 	libftprintf.a

SRC		= 	srcs/input_intake_1.c\
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

SRC_O	= 	$(SRC:%.c=%.o)
LIB		= 	ar rc
COMPILE	= 	gcc

GREEN	= 	\033[38;5;46m
WHITE	= 	\033[38;5;15m
GREY	= 	\033[38;5;8m
ORANGE	= 	\033[38;5;202m
RED		= 	\033[38;5;160m

all: $(NAME)

%.o: %.c
	@echo "$(GREY)Compiling...				$(WHITE)$<"
	@$(COMPILE) -c -o $@ $<

$(NAME): $(SRC_O)
	@echo "$(ORANGE)Creating libftprint.a$(WHITE)"
	@$(LIB) $(NAME) $(SRC_O) $?
	@ranlib $(NAME)
	@echo "$(GREEN)libftprint.a created$(WHITE)"

clean:
	@rm -f $(SRC_O)
	@echo "$(RED)Cleaning all .o files$(WHITE)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Cleaning .o files & library file$(WHITE)"

re: fclean all

.PHONY: all clean fclean re

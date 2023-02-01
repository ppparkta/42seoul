# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 15:34:21 by sooyang           #+#    #+#              #
#    Updated: 2023/01/31 16:29:40 by sooyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./libftprintf.a

SRC=\
	./ft_printf.c \
	./ft_print_int.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

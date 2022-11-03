# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/27 15:34:21 by sooyang           #+#    #+#              #
#    Updated: 2022/07/27 15:34:21 by sooyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./Libft/libft.a

NAME = ./libftprintf.a

SRC=\
	./ft_printf.c \
	./ft_print_int.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C Libft
	cp $(LIBFT) $@
	ar rcs $@ $^

clean:
	$(MAKE) -C Libft clean
	/bin/rm -f $(OBJS)

fclean: clean
	$(MAKE) -C Libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

test: $(NAME)
	@$(CC) $(CFLAGS) -lftprintf -L. main.c
	@./a.out
	@rm a.out

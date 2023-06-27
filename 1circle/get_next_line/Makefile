# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 22:38:52 by sooyang           #+#    #+#              #
#    Updated: 2022/09/01 22:38:58 by sooyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./get_next_line.a

SRC = \
	  ./get_next_line.c \
	  ./get_next_line_utils.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc -c -Wall -Wextra -Werror -I. $(SRC)
	ar rcs $@ $^

clean: 
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

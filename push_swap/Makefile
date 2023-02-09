# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 20:13:15 by sooyang           #+#    #+#              #
#    Updated: 2023/02/09 18:32:02 by sooyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAG = -Wall -Wextra -Werror -fsanitize=address

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

SRC = $(addprefix ./src/, push_swap.c\
push_swap_util.c\
operator_rrx.c\
operator_rx.c\
operator_sx_px.c\
parsing.c\
ft_split.c\
stack.c\
swap.c\
less_swap.c\
)

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) -o $@ $^

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
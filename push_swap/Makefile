# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 20:13:15 by sooyang           #+#    #+#              #
#    Updated: 2023/02/01 21:00:23 by sooyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

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
)

OBJ = $(SRC:.c=.o)

SRC_BN = $(addprefix ./src/checker/, bonus_checker.c\)

OBJ_BN = $(SRC_BN:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) -o $@ $^

$(BONUS) : $(OBJ_BN)
	$(CC) $(CFLAG) -o $@ $^
	
all : $(NAME)

bonus : $(BONUS)

clean :
	$(RM) $(OBJ) $(OBJ_BN)

fclean : clean
	$(RM) $(NAME) $(BONUS)

re : fclean all

.PHONY : all clean fclean re bonus
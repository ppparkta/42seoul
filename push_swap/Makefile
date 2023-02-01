# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 20:13:15 by sooyang           #+#    #+#              #
#    Updated: 2023/01/31 18:06:19 by sooyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CFLAG = -Wall -Wextra -Werror -fsanitize=address
FT_PRINTF = make -C ft_printf

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
	$(FT_PRINTF)
	$(CC) $(CFLAG) -o $@ $^

$(BONUS) : $(OBJ_BN)
	$(FT_PRINTF)
	$(CC) $(CFLAG) -o $@ $^
	
all : $(NAME)

bonus : $(BONUS)

clean :
	$(FT_PRINTF) clean
	$(RM) $(OBJ) $(OBJ_BN)

fclean : clean
	$(RM) $(NAME) $(BONUS) ft_printf/libftprintf.a

re : fclean all

.PHONY : all clean fclean re bonus
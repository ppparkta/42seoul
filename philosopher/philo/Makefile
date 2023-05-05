# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 17:57:19 by sooyang           #+#    #+#              #
#    Updated: 2023/04/28 17:57:20 by sooyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CFLAG=-Wall -Wextra -Werror -fsanitize=address
%.o : %.c
	&(CC) $(CFLAG) -c $< -o <@
SRC=$(addprefix ./src/,\
main.c)

OBJ=$(SRC:.c=.o)

BONUS_OBJ=$(BONUS_SRC:.c=.o)

ifdef WITH_BONUS
	OBJS=$(OBJ:.c=.o)
else
	OBJS=$(BONUS_OBJ:.c=.o)
endif

all:$(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAG) -o -$@ $^

bonus:
	@make WITH_BONUS=1 all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

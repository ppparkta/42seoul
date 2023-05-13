NAME = philo

CFLAG = -Wall -Wextra -Werror #-fsanitize=thread -g3

%.o : %.c
	@$(CC) $(CFLAG) -c $< -o $@

SRC = $(addprefix ./src/, \
main.c \
init.c \
ft_atoi.c \
life_cycle_utils.c \
philo_life_cycle.c \
take_fork.c \
utils.c \
monitoring.c)

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		@$(CC) $(CFLAG) -o $@ $^

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

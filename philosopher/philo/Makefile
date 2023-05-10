NAME = philo

CFLAG = -Wall -Wextra -Werror #-fsanitize=thread

%.o : %.c
	@$(CC) $(CFLAG) -c $< -o $@

SRC = $(addprefix ./src/, \
main.c \
init.c \
philo_behavior.c \
philo_enter.c \
set_time.c \
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

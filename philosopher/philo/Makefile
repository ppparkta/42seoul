NAME = philo

CFLAG = -Wall -Wextra -Werror -fsanitize=address -g3

%.o : %.c
	@arch -x86_64 $(CC) $(CFLAG) -c $< -o $@

SRC = $(addprefix ./src/, \
main.c \
init.c \
init_mutex.c \
philo_life_cycle.c \
error.c \
set_time.c \
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

NAME = philo

CFLAG = -Wall -Wextra -Werror -fsanitize=thread

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

#BONUS_OBJ=$(BONUS_SRC:.c=.o)

#ifdef WITH_BONUS
	OBJS=$(OBJ:.c=.o)
#else
#	OBJS=$(BONUS_OBJ:.c=.o)
#endif

all : $(NAME)

$(NAME) : $(OBJS)
		@$(CC) $(CFLAG) -o $@ $^

#bonus :
#	@make WITH_BONUS=1 all

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re #bonus

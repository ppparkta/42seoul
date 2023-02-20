NAME = pipex

CFLAG = -Wall -Wextra -Werror -fsanitize=address

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

SRC = $(addprefix ./bonus/,\
main_bonus.c \
pipex_bonus.c \
ft_split_bonus.c \
parsing_bonus.c \
util_bonus.c \
execute_bonus.c) \

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
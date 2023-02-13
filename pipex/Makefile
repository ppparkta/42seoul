NAME = pipex

CFLAG = -Wall -Wextra -Werror -fsanitize=address

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

SRC = $(addprefix ./src/, pipex.c\)

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) (CFLAG) -o $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

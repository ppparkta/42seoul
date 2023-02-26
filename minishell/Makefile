NAME = minishell

CFLAG = -Wall -Wextra -Werror

SRC = $(./main.c \
)

OBJ = $(SRC:.c=.o)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
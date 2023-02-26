NAME = minishell

CFLAG = -Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

SRC = \
	./main.c \
	./execute.c \
	./pipeline.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) -o $@ $^

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

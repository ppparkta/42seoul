NAME = pipex

CFLAG = -Wall -Wextra -Werror -fsanitize=address

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

SRC = $(addprefix ./src/,\
pipex.c \
ft_split.c \
parsing.c \
util.c) \
./get_next_line/get_next_line.c \
./get_next_line/get_next_line_utils.c \

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
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
execute_bonus.c \
heredoc_bonus.c) \
./get_next_line/get_next_line.c \
./get_next_line/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) -g $(CFLAG) -o $@ $^

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
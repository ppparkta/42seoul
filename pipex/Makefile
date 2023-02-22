NAME = pipex

CFLAG = -Wall -Wextra -Werror -fsanitize=address

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

SRC = $(addprefix ./src/,\
main.c \
pipex.c \
ft_split.c \
parsing.c \
util.c \
execute.c) 

SRC_BONUS = $(addprefix ./bonus/,\
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

BONUS_OBJS = $(SRC_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(BONUS_OBJS)
else
	OBJECTS = $(OBJ)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAG) -o $@ $^

bonus : 
	make WITH_BONUS=1 all

clean :
	$(RM) $(OBJECTS)
	$(RM) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
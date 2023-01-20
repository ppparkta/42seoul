NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
MLX = ./mlx

SRCS = ./src/main.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(SRCS)
	make -C mlx
	$(CC) $(CFLAGS) -o $@ $^ -L$(MLX) $(MLX_FLAGS) 

$.o: $.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C mlx
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


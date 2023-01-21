NAME = so_long
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = ./src/so_long.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf
	$(CC) $(CFLAGS) -o $@ $^ -L./mlx $(MLX_FLAGS) ft_printf/libftprintf.a

$.o: $.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C ft_printf clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) so_long ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re


NAME = so_long
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS = src/so_long.c \
	   src/check_map.c \
	   src/key_hook.c \
	   src/set_map.c \
	   src/so_long_util.c \
	   get_next_line/get_next_line.c \
	   get_next_line/get_next_line_utils.c \

FT_PRINTF = make -C ft_printf

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(FT_PRINTF)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJS) ft_printf/libftprintf.a

clean:
	$(FT_PRINTF) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) so_long ft_printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re


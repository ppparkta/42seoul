NAME = libft.a

SRC = ./ft_bzero.c	\
      ./ft_isalnum.c	\

OBJS = $(SRC:.C=.O)

HDRS = libft.h

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror -I $(HDRS) $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

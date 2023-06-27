# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sooyang <sooyang@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 14:57:13 by sooyang           #+#    #+#              #
#    Updated: 2022/07/20 18:17:38 by sooyang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = \
	./ft_bzero.c \
	./ft_atoi.c \
	./ft_isalnum.c \
	./ft_isalpha.c \
	./ft_isdigit.c \
	./ft_isascii.c \
	./ft_isprint.c \
	./ft_strlen.c \
	./ft_memset.c \
	./ft_memcpy.c \
	./ft_memmove.c \
	./ft_strlcpy.c \
	./ft_strlcat.c \
	./ft_strncmp.c \
	./ft_toupper.c \
	./ft_tolower.c \
	./ft_strchr.c \
	./ft_strrchr.c \
	./ft_memchr.c \
	./ft_memcmp.c \
	./ft_strnstr.c \
	./ft_calloc.c \
	./ft_strdup.c \
	./ft_substr.c \
	./ft_strjoin.c \
	./ft_strtrim.c \
	./ft_split.c \
	./ft_itoa.c \
	./ft_strmapi.c \
	./ft_striteri.c \
	./ft_putchar_fd.c \
	./ft_putstr_fd.c \
	./ft_putendl_fd.c \
	./ft_putnbr_fd.c \
BONUS = \
	./ft_lstnew.c \
	./ft_lstadd_front.c \
	./ft_lstsize.c \
	./ft_lstlast.c \
	./ft_lstadd_back.c \
	./ft_lstdelone.c \
	./ft_lstclear.c \
	./ft_lstiter.c \
	./ft_lstmap.c \
OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
ifdef WITH_BONUS
	OBJECTS = $(OBJ) $(BONUS_OBJS)
else
	OBJECTS = $(OBJ)
endif
all: $(NAME)
$(NAME): $(OBJECTS)
	gcc -c -Wall -Wextra -Werror -I. $(SRC)
	ar rcs $(NAME) $(OBJS)
bonus :
	make WITH_BONUS=1 all
clean :
	/bin/rm -f $(OBJS) $(BONUS_OBJS)
fclean : clean
	/bin/rm -f $(NAME)
re : fclean all
.PHONY: all clean fclean re bonus

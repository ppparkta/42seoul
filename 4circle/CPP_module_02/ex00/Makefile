NAME = My_First_Class_in_Orthodox_Canonical_Form

SRC = main.cpp\
	Fixed.cpp\

CXX = c++
CFALGS = -Wall -Wextra -Werror -std=c++98

%.o : %.cpp
	@$(CXX) $(CFLAG) -c $< -o $@

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CFLAGS) -o $@ $^

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = ex03

SRC = main.cpp\
	Bureaucrat.cpp\
	AForm.cpp\
	PresidentialPardonForm.cpp\
	RobotomyRequestForm.cpp\
	ShrubberyCreationForm.cpp\
	Intern.cpp\

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
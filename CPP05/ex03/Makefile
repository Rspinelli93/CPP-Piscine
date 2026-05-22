NAME = Bureaucrat

CPP = c++

FLAGS = -Wall -Werror -g -Wextra -std=c++98

SRC = \
	main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $@

%.o : %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o *_shrubbery
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
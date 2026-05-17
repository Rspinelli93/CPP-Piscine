NAME = DiamondTrap

CPP = c++

FLAGS = -Wall -Werror -g -Wextra -std=c++98 -Wno-shadow

SRC = \
	main.cpp \
	ClapTrap.cpp \
	FragTrap.cpp \
	ScavTrap.cpp \
	DiamondTrap.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $@

%.o : %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o *.replace
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
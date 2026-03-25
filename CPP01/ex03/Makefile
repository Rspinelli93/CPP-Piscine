NAME = violence

CPP = c++

FLAGS = -Wall -Werror -g -Wextra -std=c++98

SRC = \
	main.cpp \
	HumanA.cpp \
	HumanB.cpp \
	Weapon.cpp 
OBJ = $(SRC:.cpp=.o)

H_H_A = HumanA.hpp
H_H_B = HumanB.hpp
H_W = Weapon.hpp 

all: $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(H_H_A) $(H_H_B) $(H_W) $(OBJ) -o $@

%.o : %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
NAME = hi_this_is_brain

CPP = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

MAIN = main.cpp
OBJ = main.o

all: $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all re fclean clean



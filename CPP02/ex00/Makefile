NAME = Fixed

CPP = c++

FLAGS = -Wall -Werror -g -Wextra -std=c++98

SRC = \
	main.cpp \
	Fixed.cpp 

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
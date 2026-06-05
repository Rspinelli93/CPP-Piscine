NAME = PmergeMe

CPP = c++

FLAGS = -Wall -Werror -g -Wextra -std=c++98

SRC = \
	main.cpp \
	VectorMergeInsertion.cpp \
	DequeMergeInsertion.cpp \
	utils.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $@

%.o : %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
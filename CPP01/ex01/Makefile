NAME	= Moar_brainz

CC		= c++
CFLAGS	= -Werror -Wextra -g -Wall -std=c++98

SRC		= \
		main.cpp \
		newZombie.cpp \
		ZombieHorde.cpp \
		Zombie.cpp
OBJ		= $(SRC:.cpp=.o)
HEADER	= Zombie.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(HEADER) $(OBJ) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
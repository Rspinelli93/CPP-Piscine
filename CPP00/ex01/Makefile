NAME	= phonebook

CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

SRC		= \
		main.cpp \
		PhoneBook.cpp \
		Contact.cpp
OBJ		= $(SRC:.cpp=.o)
H_CONT	= Contact.hpp
H_PHONE	= PhoneBook.hpp 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(H_PHONE) $(H_CONT) $(OBJ) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
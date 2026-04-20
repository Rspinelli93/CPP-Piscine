NAME	= phonebook

CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

SRC		= \
		main.cpp \
		PhoneBook.cpp \
		Contact.cpp
OBJ		= $(SRC:.cpp=.o)
HEADERS = Contact.hpp PhoneBook.hpp 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
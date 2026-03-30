NAME = phonebook
SRC = main.cpp PhoneBook.cpp Contact.cpp
FLG = -Wall -Wextra -Werror -std=c++98
CC = c++
OBG = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBG)
	@$(CC) $(FLG) $(OBG) -o $(NAME)

%.o: %.cpp Contact.hpp PhoneBook.hpp
	@$(CC) $(FLG) -c $< -o $@

clean:
	@rm -f $(OBG)
fclean: clean
	@rm -f $(NAME)

re: fclean all
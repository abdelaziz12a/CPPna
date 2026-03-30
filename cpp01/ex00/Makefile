NAME = zombie
SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

FLG = -Wall -Wextra -Werror -std=c++98
CC = c++
OBG = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBG)
	@$(CC) $(FLG) $(OBG) -o $(NAME)

%.o: %.cpp Zombie.hpp
	@$(CC) $(FLG) -c $< -o $@

clean:
	@rm -f $(OBG)
fclean: clean
	@rm -f $(NAME)

re: fclean all


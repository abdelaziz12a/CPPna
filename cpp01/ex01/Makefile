NAME =  hordeOfZombies
SRC =  Zombie.cpp main.cpp zombieHorde.cpp

FLG = -Wall -Wextra -Werror -std=c++98
COM = c++
OBG = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBG)
	@$(COM) $(FLG) $(OBG) -o $(NAME)

%.o: %.cpp Zombie.hpp
	@$(COM) $(FLG) -c $< -o $@

clean:
	@rm -f $(OBG)

fclean: clean
	@rm -f $(NAME)

re: fclean all
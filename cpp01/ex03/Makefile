NAME = UnnecessaryViolence
SRC = main.cpp \
		Weapon.cpp HumanA.cpp HumanB.cpp

COM = c++
FLG = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ) 
	@$(COM) $(FLG) $(OBJ) -o $(NAME)

%.o: %.cpp Weapon.hpp HumanA.hpp HumanB.hpp
	@$(COM) $(FLG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
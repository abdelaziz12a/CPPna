
NAME = ClapTrap

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
COM = c++
SRC = main.cpp ClapTrap.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(COM) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp ClapTrap.hpp
	$(COM) $(CXXFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
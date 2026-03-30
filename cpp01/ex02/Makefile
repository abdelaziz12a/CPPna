
NAME = HiThisIsBrin
SRC = main.cpp 

COM = c++
FLG = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(COM) $(FLG) $(OBJ) -o $(NAME)
%.o: %.cpp
	@$(COM) $(FLG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
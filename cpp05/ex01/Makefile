NAME = Bureaucrat
COM = c++
FLAG = -Wall -Wextra -Werror --std=c++98
SRS = Bureaucrat.cpp main.cpp Form.cpp Form.hpp\

OBJ = $(SRS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(COM) $(FLAG) $(OBJ) -o $@

%.o: %.cpp Bureaucrat.hpp
	@$(COM) $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
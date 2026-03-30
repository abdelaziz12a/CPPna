
NAME = megaphone
COM = c++
FLAG = -Wall -Wextra -Werror --std=c++98
SRS = megaphone.cpp\

OBJ = $(SRS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(COM) $(FLAG) $(OBJ) -o $@

%.o: %.cpp
	@$(COM) $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all


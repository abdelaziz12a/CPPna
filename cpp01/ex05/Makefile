NAME = Harl
COM = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Harl.cpp

OBG = ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBG}
	@${COM} ${CFLAGS} -o ${NAME} ${OBG}

%.o: %.cpp Harl.hpp
	@${COM} ${CFLAGS} -c $< -o $@

clean:
	@rm -rf ${OBG}

fclean: clean
	@rm -rf ${NAME}

re: fclean all

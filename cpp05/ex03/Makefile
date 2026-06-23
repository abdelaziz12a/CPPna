NAME = Bureaucrat
COM = c++
FLAG = -Wall -Wextra -Werror --std=c++98
SRS = Bureaucrat.cpp main.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp\
		PresidentialPardonForm.cpp Intern.cpp

HEDERS = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp\
			 PresidentialPardonForm.hpp Intern.hpp
OBJ = $(SRS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(COM) $(FLAG) $(OBJ) -o $@

%.o: %.cpp $(HEDERS)
	@$(COM) $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
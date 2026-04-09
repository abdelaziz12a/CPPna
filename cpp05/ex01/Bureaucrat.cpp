
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : name("default"), grade(150) 
{
    std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &Name, int grade) : name(Name)
{
    std::cout << "Bureaucrat Constructor called" << std::endl;

    if (grade < 1)
        throw GradeTooHighException();
    
    if (grade > 150)
        throw GradeTooLowException();

    this->grade = grade;

    std::cout << "Bureaucrat " << this->getName() << " added successfully." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat Copy Constructor called " << std::endl;
    // *this = other; TRY TO USE THIS 
    std::cout << other.getName() << "copy into successfully." << this->getName() << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &other)
{
    std::cout << "Bureaucrat Assignation operator called" << std::endl;

    if (this == &other)
		return *this;

	this->grade = other.getGrade();

	return *this;
}

void Bureaucrat::increment_B()
{
    if (this->getGrade() == 1)
        throw GradeTooHighException();
    else 
        this->grade -= 1;
}
void Bureaucrat::decrement_B()
{
    if (this->getGrade() == 150)
        throw GradeTooLowException();
    else
       this->grade += 1; 
}

std::string  Bureaucrat::getName() const {return (name);}
int Bureaucrat::getGrade() const { return (grade) ;}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor for " << this->getName() << " called" << std::endl;
}



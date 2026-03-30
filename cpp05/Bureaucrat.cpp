
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(const std::string &Name, int grade) : name(Name)
{
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    if (grade > 150)
    {
        throw GradeTooLowException();
    }
    this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& other)
{}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &other)
{}







































std::string  Bureaucrat::getName() const {return (name);}
int Bureaucrat::getGrade() const { return (grade) ;}


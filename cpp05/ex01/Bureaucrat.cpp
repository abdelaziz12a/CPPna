#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->grade = other.getGrade();
    return *this;
}

void Bureaucrat::signForm(Form &form)
{
    try 
    {
        form.beSigned(*this);
    }
    catch(std::exception &e)
    {
        std::cout << this->getName() << " couldn’t sign because" << e.what() << std::endl;
    }
    // form.beSigned(*this);
    // if (form.getIndication_Sin())
    //     std::cout << this->getName() << " signed " << form.getName() << std::endl;
    // else
    //     //<bureaucrat> couldn’t sign <form> because <reason>.
    //     std::cout << this->getName() << " couldn’t sign because" << std::endl;
}

void Bureaucrat::increment_B()
{
    if (this->grade == 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrement_B()
{
    if (this->grade == 150)
        throw GradeTooLowException();
    this->grade++;
}

std::string Bureaucrat::getName() const { return name; }
int         Bureaucrat::getGrade() const { return grade; }

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high!"; }
const char *Bureaucrat::GradeTooLowException::what()  const throw() { return "Grade too low!"; }

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}

Bureaucrat::~Bureaucrat() {}



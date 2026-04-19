#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm() :AForm() {}
PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm", 25, 5) , target(_target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

std::string PresidentialPardonForm::get_target() const { return (this->target);}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIndication_Sin())
        throw GradeOrSingExpaction();
    if (executor.getGrade() > this->getGradeEx())
        throw GradeOrSingExpaction();

    std::cout << this->get_target() << " has been pardoned by Zaphod Beeblebrox\n";
}
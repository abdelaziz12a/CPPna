#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm() :AForm() {}
PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm", 25, 5) , target(_target)
{

}

std::string PresidentialPardonForm::get_target() const { return (this->target);}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const 
{
    if (!(this->getGradeEx() < executor.getGrade()) && this->getIndication_Sin())
    {
       std::cout << this->get_target() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
    else 
        throw GradeOrSingExpaction();
}
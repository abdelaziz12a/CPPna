#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib> 

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{

}
RobotomyRequestForm::RobotomyRequestForm(std:: string _target) : AForm("RobotomyRequestForm", 72, 45) , target(_target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

std::string RobotomyRequestForm::get_target() const
{
    return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIndication_Sin())
        throw GradeOrSingExpaction();
    if (executor.getGrade() > this->getGradeEx())
        throw GradeOrSingExpaction();

    std::cout << "..traq! ....traq!. traq!....\n";
    if (rand() % 2)
        std::cout << this->get_target() << " has been robotomized successfully!\n";
    else
        std::cout << this->get_target() << " robotomy failed!\n";
}



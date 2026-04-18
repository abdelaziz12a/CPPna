#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{

}
RobotomyRequestForm::RobotomyRequestForm(std:: string _target) : AForm("RobotomyRequestForm", 72, 45) , target(_target)
{

}

std::string RobotomyRequestForm::get_target() const
{
    return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!(this->getGradeEx() < executor.getGrade()) && this->getIndication_Sin())
    {
        std::cout << this->getGradeEx() <<"  " << executor.getGrade() <<std::endl;
        std::cout << "..traq! ....traq!. traq!....\n" << this->get_target() << "has been robotomized successfully 50% of the time" << std::endl;
        
    }
    else 
        throw GradeOrSingExpaction();
}



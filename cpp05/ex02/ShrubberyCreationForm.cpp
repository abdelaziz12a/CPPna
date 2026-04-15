#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm",145,137), target(_target){}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
    if (this->Indicating_Sig)
}
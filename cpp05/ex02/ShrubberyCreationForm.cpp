#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm",145,137), target(_target){}

std::string ShrubberyCreationForm::get_target() const
{
    return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (this->getGradeEx() < executor.getGrade() || this->getIndication_Sin())
    {
        std::ofstream file((this->get_target() + "_shrubbery").c_str());

        if (!file.is_open()) {
            throw std::runtime_error("Error: could not create file");
        }

        file << "        ###\n";
        file << "       #####\n";
        file << "      #######\n";
        file << "     #########\n";
        file << "    ###########\n";
        file << "        |||\n";
        file << "        |||\n";

        file.close();
    }
    else 
        throw GradeOrSingExpaction();
}


#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm",145,137), target(_target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target){}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

std::string ShrubberyCreationForm::get_target() const
{
    return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIndication_Sin())
        throw GradeOrSingExpaction();
    if (executor.getGrade() > this->getGradeEx())
        throw GradeOrSingExpaction();

    std::ofstream file((this->get_target() + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not create file");

    file << "        ###\n";
    file << "       #####\n";
    file << "      #######\n";
    file << "     #########\n";
    file << "    ###########\n";
    file << "        |||\n";
    file << "        |||\n";
    file.close();
}


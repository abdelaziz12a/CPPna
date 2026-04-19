#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP


#include "AForm.hpp"

class AForm ;


class ShrubberyCreationForm : public AForm
{
    std::string target;

    public :
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string _target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);


    std::string get_target() const;

 
    void execute(Bureaucrat const &executor) const;
    virtual ~ShrubberyCreationForm(){}
};



#endif
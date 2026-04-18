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
    std::string get_target() const;

    //canoncal
    
    
    void execute(Bureaucrat const &executor) const;
    virtual ~ShrubberyCreationForm(){}
};



#endif
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_hpp


#include "AForm.hpp"



class ShrubberyCreationForm : public AForm
{
    std::string target;

    public :
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm",145,137), target(_target){}

    //canoncal
    
    
    virtual void execute(Bureaucrat const & executor);

};



#endif
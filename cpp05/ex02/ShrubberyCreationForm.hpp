#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_hpp


#include "AForm.hpp"



class ShrubberyCreationForm : public AForm
{
    std::string target;

    public :
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string _target);


    //canoncal
    
    
    void execute(Bureaucrat const & executor) const;
    virtual ~ShrubberyCreationForm(){}
};



#endif
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private :
        std::string target;
    
    public :
        PresidentialPardonForm();
        PresidentialPardonForm(std::string _target);


        std::string get_target() const;

        void execute(Bureaucrat const &executor) const;

        ~PresidentialPardonForm(){};


};



#endif
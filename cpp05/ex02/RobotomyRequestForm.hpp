#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
    private :

        std::string target;
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(std:: string _target);

        std::string get_target() const;

        void execute(Bureaucrat const &executor) const;


        ~RobotomyRequestForm(){};

};



#endif
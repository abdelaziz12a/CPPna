#ifndef FORM_HPP
#define FORM_HPP

#include <Bureaucrat.hpp>
#include <iostream>

class Form 
{
    private:
        std::string name_form;
        bool Indicating_Sig;
        const int grade_TO_SIN;
        const int grade_TO_EX;

    public :

        Form();
        Form(std::string &Name, const int &G_tosing, const int &G_EX);

        //copy constructurn
        //copy assigment
        
        class GradeTooHighException : public std::exception
        {
            public :
                const char * what() const throw();
                
        };  

        class GradeTooLowException : public std::exception
        {
            public :
                const char * what() const throw();
                
        };
        
        //members
        void beSigned(Bureaucrat &bureaucrat);

        //getters
        std::string getName() const;
        bool getIndication_Sin() const;
        int getGradeSin() const;
        int getGradeEx() const;

        ~Form();
};

std::ostream& operator<<(std::ostream &os, const Form &obj);


#endif
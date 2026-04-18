#ifndef AFORM_HPP
#define AFORM_HPP


#include <iostream>

class Bureaucrat;

class AForm 
{
    private:
        std::string name_Aform;
        bool Indicating_Sig;
        const int grade_TO_SIN;
        const int grade_TO_EX;

    public :

        AForm();
        AForm(const std::string &Name, const int &G_tosing, const int &G_EX);

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
        class GradeOrSingExpaction : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        //members
        void beSigned(Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;

        //getters
        std::string getName() const;
        bool getIndication_Sin() const;
        int getGradeSin() const;
        int getGradeEx() const;

        ~AForm();



};

std::ostream& operator<<(std::ostream &os, const AForm &obj);


#endif
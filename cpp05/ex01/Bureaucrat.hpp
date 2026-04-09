
#ifndef BUREAURAT_HPP
#define BUREAURAT_HPP


#include <iostream>


class Bureaucrat
{
    private :

        const std::string name;
        int  grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string &Name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat &other);
        Bureaucrat& operator<<(Bureaucrat &other);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        std::string getName() const;
        int getGrade() const;

        void increment_B();
        void decrement_B();

        ~Bureaucrat();
};

#endif
 

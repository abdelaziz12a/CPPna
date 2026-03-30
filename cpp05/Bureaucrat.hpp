
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
        Bureaucrat(Bureaucrat& other);
        Bureaucrat& operator=(Bureaucrat &other);
        

        class GradeTooHighException : public std::exception
        {
            public :
                const char* what() const noexcept
                {
                    return ("Grade too high");
                }
        };

        class  GradeTooLowException : public std::exception
        {
            public :
                const char* what() const noexcept
                {
                    return ("Grade too low");
                }
        };

        std::string getName() const;
        int getGrade() const;
        // void increment_B();
        // void decrement_B();

        //vertual ~Bureaucrat();

};



#endif
 

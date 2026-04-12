#include "Bureaucrat.hpp"


#include "Bureaucrat.hpp"

int main()
{
    // Test normal (+)
    try {
        Bureaucrat b("Aziz", 2);
        std::cout << b << std::endl; //operator
        b.increment_B();
        std::cout << b << std::endl;
        b.increment_B(); // GradeTooHighException
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // invalid grade (construction)
    try {
        Bureaucrat b("Bad", 0); // GradeTooHighException
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    //decrement 
    try {
        Bureaucrat b("Low", 150);
        b.decrement_B(); // throws GradeTooLowException
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}
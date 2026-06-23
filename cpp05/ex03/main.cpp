
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib> 

int main()
{
    srand(time(0));
    Intern intern;

    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat low("Low", 150);
        
        AForm* f1 = intern.makeForm("shrubbery creation", "home");
        if (f1)
        {
            boss.signForm(*f1);
            boss.executeForm(*f1);
            delete f1;
        }

        std::cout << "---------------------\n";

        AForm* f2 = intern.makeForm("robotomy request", "Bender");
        if (f2)
        {
            boss.signForm(*f2);
            boss.executeForm(*f2);
            delete f2;
        }

        std::cout << "---------------------\n";

        AForm* f3 = intern.makeForm("presidential pardon", "Arthur");
        if (f3)
        {
            boss.signForm(*f3);
            boss.executeForm(*f3);
            delete f3;
        }

        std::cout << "---------------------\n";

        AForm* f5 = intern.makeForm("shrubbery creation", "garden");
        if (f5)
        {
            low.signForm(*f5);
            low.executeForm(*f5);
            delete f5;
        }

        std::cout << "---------------------\n";

        AForm* f4 = intern.makeForm("pizza form", "me");
        if (f4)
            delete f4;
    }
    catch (std::exception &e) {
        std::cout << "Error creating Bureaucrat: " << e.what() << std::endl;
    }
    

    

    return 0;
}



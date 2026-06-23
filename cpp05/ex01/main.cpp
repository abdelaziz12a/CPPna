#include "Bureaucrat.hpp"




int main()
{
    try {

        Bureaucrat b("Aziz", 102);
        std::cout << b << std::endl; 
        b.increment_B();
        std::cout << b << std::endl;

        Form F;
        std::cout << F << std::endl;

        Form FORM("tax", 100, 50);
        std::cout << FORM << std::endl;
        b.signForm(FORM);
        std::cout << FORM.getIndication_Sin() << std::endl;

        Form FORM_1("annual tax", 150, 50);
        std::cout << FORM_1 << std::endl;
        b.signForm(FORM_1);
        std::cout << FORM_1.getIndication_Sin() << std::endl;
    }

    catch (std::exception &e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

}
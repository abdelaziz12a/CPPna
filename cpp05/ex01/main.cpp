#include "Bureaucrat.hpp"


#include "Bureaucrat.hpp"

int main()
{
    // Test normal (+)
    try {
        Bureaucrat b("Aziz", 102);
        std::cout << b << std::endl; //operator
        // b.increment_B();
        // std::cout << b << std::endl;
        // std::cout << "{add aziz and increment grade are sucsess}" << std::endl;
        std::cout << "{test 01}" << std::endl;
        // Form F;
        // std::cout << F << std::endl;
        Form FORM("dariba", 100, 50);
        std::cout << FORM << std::endl;
        b.signForm(FORM);

        Form FORM_1("war9a dyal do", 150, 50);
        std::cout << FORM_1 << std::endl;
        b.signForm(FORM_1);
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

}
#include "Bureaucrat.hpp"


int main()
{
    try
    {
        Bureaucrat b("aziz", 2);
        std::cout << b.getGrade() << std::endl;

        b.increment_B();
        std::cout << b.getGrade() << std::endl;

        b.increment_B();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
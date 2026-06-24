#include "ScalarConverter.hpp"



int main(int ac, char **av)
{
    if (ac != 1)
    {
        std::cout << "Ivalid" << std::endl;
        return 0;
    }
    std::string str = av[1];
    ScalarConverter::convert(str);
    




}
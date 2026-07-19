#include "ScalarConverter.hpp"
#include <limits>
#include <iomanip>
#include <limits.h>
#include <float.h>
#include <cerrno> 
#include <cstdlib>
    
enum e_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};


ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &){}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &){return *this;}
ScalarConverter::~ScalarConverter(){}


e_type detectType(const std::string& str)
{
    if (str.length() == 1 && !isdigit(str[0]))
        return CHAR;

    if (str == "nan" || str == "nanf" ||
        str == "+inf" || str == "-inf" ||
        str == "+inff" || str == "-inff")
        return PSEUDO;

    char *end;

    errno = 0;
    strtol(str.c_str(), &end, 10);
    if (errno == 0 && *end == '\0')
        return INT;

    if (str[str.length() - 1] == 'f')
    {
        std::string withoutF = str.substr(0, str.length() - 1);
        errno = 0;
        strtod(withoutF.c_str(), &end);
        if (errno == 0 && *end == '\0' && withoutF.find('.') != std::string::npos)
            return FLOAT;
    }

    errno = 0;
    strtod(str.c_str(), &end);
    if (errno == 0 && *end == '\0' && str.find('.') != std::string::npos)
        return DOUBLE;

    return INVALID;
}

void handelInvalid()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void handelChar(const char c)
{
    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void handelInt(const std::string &input)
{
   
    std::stringstream ss(input);
    int OrgInt;

    ss >> OrgInt;
    if (!ss.fail())
    {
        handelInvalid();
        return ;
    }
    //char 
    if (OrgInt < 0 || OrgInt > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<int>(OrgInt)))
        std::cout << "char: Non displayable" << std::endl;
    // int, float, double 
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "int: " << OrgInt << std::endl;
    std::cout << "float: " << static_cast<float>(OrgInt) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(OrgInt) << std::endl;
}

void handelFloat(const std::string &input)
{
    std::string withoutF = input.substr(0, input.length() - 1);
    errno = 0;
    double value = strtod(withoutF.c_str(), NULL);

    if (errno == ERANGE || value < -FLT_MAX || value > FLT_MAX)
    {
        handelInvalid();
        return;
    }

    // char
    if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    // int
    if (value < INT_MIN || value > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    // float and double
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << value << std::endl;
}

void handelDouble(const std::string &input)
{
    errno = 0;
    double value = strtod(input.c_str(), NULL);

    if (errno == ERANGE || value < -DBL_MAX || value > DBL_MAX)
    {
        handelInvalid();
        return;
    }

    // char
    if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    // int
    if (value < INT_MIN || value > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    // float
    std::cout << std::fixed << std::setprecision(1);
    if (value < -FLT_MAX || value > FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;

    // double
    std::cout << "double: " << value << std::endl;
}



void ScalarConverter::convert(const std::string &input)
{
    e_type type = detectType(input);

    if (type == PSEUDO)
    {
        if (input == "nan" || input == "nanf") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (input == "+inf" || input == "+inff") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else if (input == "-inf" || input == "-inff") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
    }
    else if (type == CHAR)
        handelChar(input[0]);
    else if (type == INT)
        handelInt(input);
    else if (type == FLOAT)
        handelFloat(input);
    else if (type == DOUBLE)
        handelDouble(input);
    else
        handelInvalid();
}
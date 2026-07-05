#include "ScalarConverter.hpp"
#include <limits>
#include <iomanip>
#include <limits.h>

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
ScalarConverter::ScalarConverter(const ScalarConverter &other){}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other){}
ScalarConverter::~ScalarConverter(){}


e_type detectType(const std::string& str)
{
    // Single non-digit character → char
    if (str.length() == 1 && !isdigit(str[0]) && !isprint(str[0]) == false)
        return CHAR;

    // Pseudo literals
    if (str == "nan" || str == "nanf" ||
        str == "+inf" || str == "-inf" ||
        str == "+inff" || str == "-inff")
        return PSEUDO;

    char *end;

    // Try int via strtol
    errno = 0;
    strtol(str.c_str(), &end, 10);
    if (errno == 0 && *end == '\0')
        return INT;

    // Try float: strtod on the string minus trailing 'f'
    if (str[str.length() - 1] == 'f')
    {
        std::string withoutF = str.substr(0, str.length() - 1);
        errno = 0;
        strtod(withoutF.c_str(), &end);
        if (errno == 0 && *end == '\0' && withoutF.find('.') != std::string::npos)
            return FLOAT;
    }

    // Try double via strtod
    errno = 0;
    strtod(str.c_str(), &end);
    if (errno == 0 && *end == '\0' && str.find('.') != std::string::npos)
        return DOUBLE;

    return INVALID;
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
    char *end;
    errno = 0;
    long value = std::strtol(input.c_str(), &end, 10);

    if (errno == ERANGE || value < INT_MIN || value > INT_MAX)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    int val = static_cast<int>(value);

    // char
    if (val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(val))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;

    // int, float, double always print
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "int: " << val << std::endl;
    std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(val) << std::endl;
}

void handelFloat(const std::string &input)
{
    char *end;
    errno = 0;
    double value = strtod(input.c_str(), &end);
    if (errno == ERANGE)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    float val = static_cast<float>(value);
    

    


}
void handeDouble(const std::string &input)
{

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
    if (type == CHAR)
    {
        handelChar(input[0]);
    }
    if (type == INT)
    {
        handelInt(input);
    }
    if (type == FLOAT)
    {
        handelFloat(input);
        //.............
    }
    if (type == DOUBLE)
    {
    
        //..............
    }
    if (type == INVALID)
    {

    }

}
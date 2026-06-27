#include "ScalarConverter.hpp"
#include <limits>

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

bool isPseudo(const std::string& str)
{
    return (str == "nan" ||
        str == "nanf" ||
        str == "+inf" ||
        str == "-inf" ||
        str == "+inff" ||
        str == "-inff");
}
bool isChar(const std::string& str)
{
    if (str.length() == 1 && !isdigit(str[0]))
        return true;
    return false;
}
bool isInt(const std::string& str)
{
    int i = 0;

    if (str[0] == '-' ||  str[0] == '+')
        i++;

    if (i == str.length())
        return false;

    while(i < str.length())
    {
        if (isdigit(str[i]))
            i++;
        else
            return false;
    }
    return true;
}

bool isDecimal(const std::string &str, bool hasF)
{
    size_t i = 0;
    bool hasDot = false;
    bool beforeDot = false;
    bool afterDot = false;


    if (str[i] == '+' || str[i] == '-')
        i++;

    if (i >= str.length())
        return false;

    while (i < str.length())
    {
        if (isdigit(str[i]))
        {
            if (!hasDot)
                beforeDot = true;
            else
                afterDot = true;
        }
        else if (str[i] == '.')
        {
            if (hasDot || !beforeDot)
                return false;

            hasDot = true;
        }
        else if (str[i] == 'f')
        {
            if (!hasF || i != str.length() - 1)
                return false;

            return hasDot && beforeDot && afterDot;
        }
        else
            return false;

        i++;
    }

    return !hasF && hasDot && beforeDot && afterDot;
}

bool isFloat(const std::string &str)
{
    return isDecimal(str, true);
}
bool isDouble(const std::string &str)
{
    return isDecimal(str, false);
}

e_type detectType(const std::string& str)
{
    if (isPseudo(str))
        return PSEUDO;

    if (isChar(str))
        return CHAR;

    if (isInt(str))
        return INT;

    if (isFloat(str))
        return FLOAT;

    if (isDouble(str))
        return DOUBLE;

    return INVALID;      
}

void print_double(double d, bool unvalid)
{

    if(unvalid)
        std::cout << "double : impossible" << std::endl;
    else
        std::cout << "double : " << d << std::endl;
}

void print_float(float f, bool unvalid)
{
    if(unvalid)
        std::cout << "float : impossible" << std::endl;
    else
        std::cout << "float : " << f << std::endl;
}

void print_int(int i, bool unvalid)
{
    if(unvalid)
        std::cout << "int : impossible" << std::endl;
    else
        std::cout << "int : " << i << std::endl;
}

void print_char(char c, bool unvalid)
{
    if (unvalid)
    {
        std::cout << "char: impossible\n";
        return;
    }
    if(isprint(c))
        std::cout << "char : '" << c << "'" << std::endl;
    else 
        std::cout << "char : Non displayable" << std::endl;
}

void handel_char(const std::string input)
{
    //char
    char c = input[0];
    print_char(c, false);
    //int
    int i = static_cast<int>(c);
    print_int(i, false);
    //flout 
    float f = static_cast<float>(c);
    print_float(f, false);
    //double
    double d = static_cast<double>(c);
    print_double(d, false);
}

void handel_int(long value)
{
    // char
    if (value < std::numeric_limits<char>::min() ||
        value > std::numeric_limits<char>::max())
    {
        print_char(0, true);
    }
    else
    {
        char c = static_cast<char>(value);
        print_char(c, false);
    }
    // int
    if (value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max())
    {
        print_int(0, true);
    }
    else
    {
        int i = static_cast<int>(value);
        print_int(i, false);
    }
    // float
    float f = static_cast<float>(value);
    print_float(f, false);
    // double
    double d = static_cast<double>(value);
    print_double(d, false);
}

void handel_float(long f)
{
    
}

void ScalarConverter::convert(const std::string &input)
{

    switch(detectType(input))
    {
        case CHAR:
            handel_char(input);
            break;

        case INT:
            char *end;
            long value = std::strtol(input.c_str(), &end, 10);
            handel_int(value);
            break;

        case FLOAT:
            char *end;
            long value = std::strtol(input.c_str(), &end, 10);
            handel_float(value);
            break;

        case DOUBLE:
        
            break;
        
        case PSEUDO:
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
            break;
      
    }
    

}
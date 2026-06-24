#include "ScalarConverter.hpp"

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

e_type isPseudo()
{

}
e_type isChar()
{
    
}
e_type isInt()
{
    
}
e_type isFloat()
{
    
}
e_type isDouble()
{
    
}

e_type detectType(const std::string& str)
{
    if (isPseudo())
        return PSEUDO;

    if (isChar())
        return CHAR;

    if (isInt())
        return INT;

    if (isFloat())
        return FLOAT;

    if (isDouble())
        return DOUBLE;

    return INVALID;      
}

void ScalarConverter::convert(const std::string &input)
{
    e_type type = detectType(input);
    

}
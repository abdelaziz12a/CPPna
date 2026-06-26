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

void ScalarConverter::convert(const std::string &input)
{
    e_type type = detectType(input);
    

}
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}



// bool isPseudo(const std::string& str)
// {
//     return (str == "nan" ||
//         str == "nanf" ||
//         str == "+inf" ||
//         str == "-inf" ||
//         str == "+inff" ||
//         str == "-inff");
// }
// bool isChar(const std::string& str)
// {
//     if (str.length() == 1 && !isdigit(str[0]))
//         return true;
//     return false;
// }
// bool isInt(const std::string& str)
// {
//     int i = 0;

//     if (str[0] == '-' ||  str[0] == '+')
//         i++;

//     if (i == str.length())
//         return false;

//     while(i < str.length())
//     {
//         if (isdigit(str[i]))
//             i++;
//         else
//             return false;
//     }
//     return true;
// }

// bool isDecimal(const std::string &str, bool hasF)
// {
//     size_t i = 0;
//     bool hasDot = false;
//     bool beforeDot = false;
//     bool afterDot = false;


//     if (str[i] == '+' || str[i] == '-')
//         i++;

//     if (i >= str.length())
//         return false;

//     while (i < str.length())
//     {
//         if (isdigit(str[i]))
//         {
//             if (!hasDot)
//                 beforeDot = true;
//             else
//                 afterDot = true;
//         }
//         else if (str[i] == '.')
//         {
//             if (hasDot || !beforeDot)
//                 return false;

//             hasDot = true;
//         }
//         else if (str[i] == 'f')
//         {
//             if (!hasF || i != str.length() - 1)
//                 return false;

//             return hasDot && beforeDot && afterDot;
//         }
//         else
//             return false;

//         i++;
//     }

//     return !hasF && hasDot && beforeDot && afterDot;
// }

// bool isFloat(const std::string &str)
// {
//     return isDecimal(str, true);
// }
// bool isDouble(const std::string &str)
// {
//     return isDecimal(str, false);
// }

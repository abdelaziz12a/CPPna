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

// ─── Canonical Form (private → not instantiable) ────────────────────────────
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}

// ─── Type detection helpers ──────────────────────────────────────────────────
static bool isPseudo(const std::string &s)
{
    return (s == "nan" || s == "nanf" ||
            s == "+inf" || s == "-inf" ||
            s == "+inff" || s == "-inff");
}

static bool isChar(const std::string &s)
{
    return (s.length() == 1 && !isdigit(s[0]));
}

static bool isInt(const std::string &s)
{
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.length())
        return false;
    while (i < s.length())
    {
        if (!isdigit(s[i]))
            return false;
        i++;
    }
    return true;
}

static bool isDecimal(const std::string &s, bool hasF)
{
    size_t i = 0;
    bool hasDot = false, beforeDot = false, afterDot = false;

    if (i < s.length() && (s[i] == '+' || s[i] == '-'))
        i++;
    if (i >= s.length())
        return false;

    while (i < s.length())
    {
        if (isdigit(s[i]))
        {
            if (!hasDot) beforeDot = true;
            else         afterDot  = true;
        }
        else if (s[i] == '.')
        {
            if (hasDot || !beforeDot)
                return false;
            hasDot = true;
        }
        else if (s[i] == 'f')
        {
            if (!hasF || i != s.length() - 1)
                return false;
            return hasDot && beforeDot && afterDot;
        }
        else
            return false;
        i++;
    }
    return !hasF && hasDot && beforeDot && afterDot;
}

static e_type detectType(const std::string &s)
{
    if (isPseudo(s))           return PSEUDO;
    if (isChar(s))             return CHAR;
    if (isInt(s))              return INT;
    if (isDecimal(s, true))    return FLOAT;
    if (isDecimal(s, false))   return DOUBLE;
    return INVALID;
}

// ─── Printers (handle impossible + decimal formatting) ──────────────────────
static void printChar(double val, bool overflow)
{
    if (overflow || val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<int>(val)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
}

static void printInt(double val, bool overflow)
{
    if (overflow || std::isnan(val) || std::isinf(val) ||
        val > static_cast<double>(INT_MAX) || val < static_cast<double>(INT_MIN))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
}

static void printFloat(double val, bool overflow)
{
    if (overflow)
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }
    float f = static_cast<float>(val);
    if (std::isnan(f))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << "float: " << (f > 0 ? "+" : "-") << "inff" << std::endl;
    else
    {
        std::ostringstream oss;
        oss.precision(1);
        oss << std::fixed << f;
        std::cout << "float: " << oss.str() << "f" << std::endl;
    }
}

static void printDouble(double val, bool overflow)
{
    if (overflow)
    {
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (std::isnan(val))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(val))
        std::cout << "double: " << (val > 0 ? "+" : "-") << "inf" << std::endl;
    else
    {
        std::ostringstream oss;
        oss.precision(1);
        oss << std::fixed << val;
        std::cout << "double: " << oss.str() << std::endl;
    }
}

// ─── Convert ────────────────────────────────────────────────────────────────
void ScalarConverter::convert(const std::string &input)
{
    e_type type = detectType(input);

    if (type == INVALID)
    {
        std::cout << "char: impossible"   << std::endl;
        std::cout << "int: impossible"    << std::endl;
        std::cout << "float: impossible"  << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // ── Pseudo-literals ──────────────────────────────────────────────────────
    if (type == PSEUDO)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible"  << std::endl;
        if (input == "nan" || input == "nanf")
        {
            std::cout << "float: nanf"   << std::endl;
            std::cout << "double: nan"   << std::endl;
        }
        else if (input == "+inf" || input == "+inff")
        {
            std::cout << "float: +inff"  << std::endl;
            std::cout << "double: +inf"  << std::endl;
        }
        else // -inf / -inff
        {
            std::cout << "float: -inff"  << std::endl;
            std::cout << "double: -inf"  << std::endl;
        }
        return;
    }

    // ── Parse to double (our universal intermediary) ─────────────────────────
    double val = 0;
    bool   overflow = false;

    if (type == CHAR)
    {
        val = static_cast<double>(input[0]);
    }
    else // INT, FLOAT, DOUBLE
    {
        errno = 0;
        char *end;
        val = std::strtod(input.c_str(), &end);
        if (errno == ERANGE)
            overflow = true;
    }

    printChar(val, overflow);
    printInt(val, overflow);
    printFloat(val, overflow);
    printDouble(val, overflow);
}

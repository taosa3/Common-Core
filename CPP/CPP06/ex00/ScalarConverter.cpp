#include "ScalarConverter.hpp"
#include <iostream>

enum Type {
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    INVALID = 100
};

static Type getType(const std::string& literal) {
    bool hasSign = false;
    bool hasDot = false;
    bool hasF = false;
    bool hasDigit = false;

    if (literal.empty())
        return INVALID;
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return DOUBLE;
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return FLOAT;
    if (literal.length() == 1 && !isdigit(literal[0]))
        return CHAR;
    for (size_t i = 0; i < literal.length(); i++) {
        char c = literal[i];
        if (c == '-' || c == '+') {
            if (i != 0 || hasSign)
                return INVALID;
            hasSign = true;
        }
        else if (c == '.') {
            if (hasDot)
                return INVALID;
            hasDot = true;
        }
        else if (c == 'f' || c == 'F') {
            if (i != literal.length() - 1 || hasF)
                return INVALID;
            hasF = true;
        }
        else if (std::isdigit(static_cast<unsigned char>(c)))
            hasDigit = true;
        else
            return INVALID;
    }
    if (!hasDigit)
        return INVALID;
    if (hasDot && hasF)
        return FLOAT;
    if (hasDot)
        return DOUBLE;
    return INT;
}

static void printImpossible() {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

static void printChar(double value) {
    if (std::isnan(value) || std::isinf(value) || value < CHAR_MIN || value > CHAR_MAX) {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(value);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

static void printInt(double value) {
    if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX) {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(double value) {
    if (std::isnan(value))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(value)) {
        if (value > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    }
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

static void printDouble(double value) {
    if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(value)) {
        if (value > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }
    else
        std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    Type type = getType(literal);
    std::string typeName = (type == INT) ? "int" :
                      (type == CHAR) ? "char" :
                      (type == FLOAT) ? "float" :
                      (type == DOUBLE) ? "double" : "invalid";
    std::cout << "Type: " << typeName << std::endl;
    double result = 0;

    switch (type) {
        case INT:
        {
            char *end;
            long value = std::strtol(literal.c_str(), &end, 10);
            if (*end != '\0' || value < INT_MIN || value > INT_MAX) {
                printImpossible();
                return;
            }
            result = static_cast<double>(value);
            break;
        }
        case CHAR:
        {
            result = static_cast<double>(literal[0]);
            break;
        }
        case FLOAT:
        {
            char *end;
            float value = std::strtof(literal.c_str(), &end);
            std::cout << "End pointer: " << *end << std::endl;
            if (*(end + 1) != '\0') {
                printImpossible();
                return;
            }
            result = static_cast<double>(value);
            break;
        }
        case DOUBLE:
        {
            char *end;
            double value = std::strtod(literal.c_str(), &end);
            if (*end != '\0') {
                printImpossible();
                return;
            }
            result = value;
            break;
        }
        case INVALID:
        {
            printImpossible();
            return;
        }
    }
    printChar(result);
    printInt(result);
    printFloat(result);
    printDouble(result);
}
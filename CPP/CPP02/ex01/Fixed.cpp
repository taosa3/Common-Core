#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : fixedPoint(other.fixedPoint) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->fixedPoint = other.fixedPoint;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int num) : fixedPoint(num * (1 << fractionalbits)) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : fixedPoint(roundf(num * (1 << fractionalbits))) {
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const {
    return (float)fixedPoint / (1 << fractionalbits);
}

int Fixed::toInt(void) const {
    return fixedPoint / (1 << fractionalbits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}
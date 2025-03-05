#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    _value = n << _fractionalBits;
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    _value = (int)roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    _value = other._value;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _value = other._value;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat() const {
    return (float)_value / (float)(1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}
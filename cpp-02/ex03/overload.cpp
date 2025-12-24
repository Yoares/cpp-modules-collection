#include "Fixed.hpp"

// overload comparison operators

bool Fixed::operator>(const Fixed &other) const{
    return (this->_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed &other) const{
    return (this->_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed &other) const{
    return (this->_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(const Fixed &other) const{
    return (this->_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed &other) const{
    return (this->_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed &other) const{
    return (this->_fixedPointValue != other._fixedPointValue);
}

// overload arithmetic operators

Fixed Fixed::operator+(const Fixed &other) const
{
    return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return (this->toFloat() / other.toFloat());
}

// The 4 increment/decrement 

Fixed &Fixed::operator++(void)
{
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->_fixedPointValue++;
    return tmp;
}

Fixed &Fixed::operator--(void)
{
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->_fixedPointValue--;
    return tmp;
}

// Static member helpers

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}
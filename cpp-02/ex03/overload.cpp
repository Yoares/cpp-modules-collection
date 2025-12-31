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
    Fixed result;

    result.setRawBits(this->_fixedPointValue + other.getRawBits());
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;

    long long temp = this->_fixedPointValue * other.getRawBits();

    result.setRawBits(temp >> 8);
    return(result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;

    result.setRawBits(this->_fixedPointValue - other.getRawBits());
    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    long long temp = (long long)this->_fixedPointValue << 8;

    result.setRawBits(temp / other.getRawBits());
    return (result);
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
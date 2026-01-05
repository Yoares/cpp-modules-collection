#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed () 
{
    _fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}
Fixed &Fixed::operator =(const Fixed &other)
{
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed(void) {
}

int Fixed::getRawBits(void) const 
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw; 
}

Fixed::Fixed(const int integer)
{
    this->_fixedPointValue = integer << _fractionalBits;
}

Fixed::Fixed(const float flt)
{
    this->_fixedPointValue = (int)roundf(flt * (1 << _fractionalBits));
}

float Fixed::toFloat( void ) const
{
    return ((float)this->_fixedPointValue / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const
{
    return (this->_fixedPointValue >> this->_fractionalBits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
    o << i.toFloat();
    return (o);
}

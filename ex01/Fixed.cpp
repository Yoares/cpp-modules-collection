#include "Fixed.hpp"

Fixed::Fixed () 
{
    std::cout << "Default constructor called" << std::endl;
    _fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
Fixed &Fixed::operator =(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw; 
}
// this is the following added 

Fixed::Fixed(const int integer)
{
    this->_fixedPointValue = integer << _fractionalBits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float flt)
{
    this->_fixedPointValue = (int)roundf(flt * (1 << _fractionalBits));
    std::cout << "Float constructor called" << std::endl;
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


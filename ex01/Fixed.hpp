#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
    private :
        int	_fixedPointValue;
    	static const int	_fractionalBits;
	public :
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator =(const Fixed &other);
		~Fixed();
		// added
		Fixed(const int integer);
		Fixed(const float flt);

		int     getRawBits(void) const;
    	void    setRawBits(int const raw);
		// added
		float	toFloat( void ) const;
		int		toInt( void ) const;

};
std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
    private :
        int	_fixedPointValue;
    	static const int	_fractionalBits = 8;
	public :
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator =(const Fixed &other);
		~Fixed();
		Fixed(const int integer);
		Fixed(const float flt);

		int     getRawBits(void) const;
    	void    setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
		// overload comparison operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		// overload arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		// The 4 increment/decrement 
		Fixed &operator++(void); 
		Fixed operator++(int);   
		Fixed &operator--(void);
		Fixed operator--(int);
		// Static functions
		static Fixed & min( Fixed &a, Fixed &b );
		static const Fixed & min( const Fixed &a, const Fixed &b );
		static Fixed & max( Fixed &a, Fixed &b );
		static const Fixed & max( const Fixed &a, const Fixed &b );

};
std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif
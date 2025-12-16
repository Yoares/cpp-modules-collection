#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    if (a < b)
        std::cout << "yes" << std::endl;
    else   
        std::cout << "no" << std::endl;

    return 0;
}

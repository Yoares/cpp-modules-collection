#include <iostream>
#include "Fixed.hpp"

class Point{
    private :
        Fixed const x;
        Fixed const y;
    public :
        Point();
        Point(const float f1, const float f2);
        Point(const Point &other);
        Point &operator =(const Point &other);
        ~Point();

        Fixed getX(void) const;
        Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
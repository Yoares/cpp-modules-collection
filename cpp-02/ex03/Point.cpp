#include <Point.hpp>

Point::Point() : x(0), y(0) {}

Point::Point(const float f1, const float f2) : x(f1), y(f2) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point &other) {
    return *this;
}

Point::~Point() {}

Fixed Point::getX(void) const{
    return this->x;
}
Fixed Point::getY(void) const{
    return this->y;
}

bool Point::bsp( Point const a, Point const b, Point const c, Point const point)
{
    
}
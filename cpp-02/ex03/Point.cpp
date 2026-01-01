#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float f1, const float f2) : x(f1), y(f2) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point &other)
{
    (void)other;
    return *this;
}

Point::~Point() {}

Fixed Point::getX(void) const{
    return this->x;
}
Fixed Point::getY(void) const{
    return this->y;
}

static Fixed cross_product(Point const& a, Point const& b, Point const& p)
{
    return((b.getX() - a.getX()) * (p.getY() - a.getY())
            - (b.getY() - a.getY()) * (p.getX() - a.getX()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed ab = cross_product(a, b, point);
    Fixed bc = cross_product(b, c, point);
    Fixed ca = cross_product(c, a, point);

    bool allpositive = (ab > 0 && bc > 0 && ca > 0);
    bool allnegative = (ab < 0 && bc < 0 && ca < 0);

    return(allpositive || allnegative);
}

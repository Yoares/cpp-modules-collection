#include <iostream>
#include "Point.hpp"

int main(void)
{
    // Triangle ABC
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);

    // Point clearly INSIDE
    Point p1(1, 1);

    //Point clearly OUTSIDE
    Point p2(5, 5);

    //Point ON EDGE (should be false)
    Point p3(2, 0);

    //Point ON VERTEX (should be false)
    Point p4(0, 0);

    std::cout << "p1 inside: ";
    if (bsp(a, b, c, p1))
        std::cout << "true";
    else
        std::cout << "false";
    std::cout << std::endl;

    std::cout << "p2 outside: ";
    if (bsp(a, b, c, p2))
        std::cout << "true";
    else
        std::cout << "false";
    std::cout << std::endl;

    std::cout << "p3 on edge: ";
    if (bsp(a, b, c, p3))
        std::cout << "true";
    else
        std::cout << "false";
    std::cout << std::endl;

    std::cout << "p4 on vertex: ";
    if (bsp(a, b, c, p4))
        std::cout << "true";
    else
        std::cout << "false";
    std::cout << std::endl;

    return 0;
}

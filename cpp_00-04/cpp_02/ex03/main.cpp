#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 5.0f);

    Point inside(5.0f, 2.0f);
    Point outside(20.0f, 20.0f);
    Point edge(0.0f, 0.0f);

    std::cout << bsp(a,b,c, inside) << std::endl;
    std::cout << bsp(a,b,c, outside) << std::endl;
    std::cout << bsp(a,b,c, edge) << std::endl;
    return 0;
}
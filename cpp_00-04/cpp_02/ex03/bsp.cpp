#include "Point.hpp"

static float area(const Point &a, const Point &b, const Point &c) {
    float x1 = a.getX().toFloat();
    float y1 = a.getY().toFloat();
    float x2 = b.getX().toFloat();
    float y2 = b.getY().toFloat();
    float x3 = c.getX().toFloat();
    float y3 = c.getY().toFloat();
    return (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) > 0 ? 
        (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2 :
        -(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float totalArea = area(a,b,c);
    float area1 = area(point,b,c);
    float area2 = area(a,point,c);
    float area3 = area(a,b,point);
    if (area1 <= 0 || area2 <= 0 || area3 <= 0)
        area1 = -area1, area2 = -area2, area3 = -area3;
    if (area1 + area2 + area3 == totalArea && area1 != 0 && area2 != 0 && area3 != 0)
        return true;
    return false;
}
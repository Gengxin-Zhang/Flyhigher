/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Point2D.h"
#include <cmath>
using std::sqrt, std::to_string;

/**
 * Point2D implementation
 */


Point2D::Point2D() {
    x = 0;
    y = 0;
}

Point2D::Point2D(const double x, const double y) {
    this->x = x;
    this->y = y;
}

Point2D::Point2D(const Point2D& ano) {
    x = ano.x;
    y = ano.y;
}

double Point2D::distanceTo(const Point2D& ano) const{
    double deltax = x - ano.x;
    double deltay = y - ano.y;
    return sqrt(deltax*deltax + deltay*deltay);
}

double Point2D::getX() const{
    return x;
}

double Point2D::getY() const{
    return y;
}

Point2D Point2D::moveX(const double x) const{
    return Point2D(this->x + x, y);
}

Point2D Point2D::moveY(const double y) const{
    return Point2D(x, this->y + y);
}

string Point2D::toString() const{
    return "[Point2D] (" + to_string(x) + ", " + to_string(y) + ")";
}

string Point2D::getClassName() const{
    return "Point2D";
}

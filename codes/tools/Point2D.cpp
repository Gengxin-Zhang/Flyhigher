/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Point2D.h"
#include <cmath>
using std::sqrt;

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

void Point2D::moveX(const double x) {
    this->x += x;
}

void Point2D::moveY(const double y) {
    this->y += y;
}
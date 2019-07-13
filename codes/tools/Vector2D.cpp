/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Vector2D.h"
#include <cmath>
using std::sqrt, std::sin, std::cos;

/**
 * Vector2D implementation
 */


Vector2D::Vector2D() {
    x = 0;
    y = 0;
}

Vector2D::Vector2D(double x, double y) {
    this->x = x;
    this->y = y;
}

Vector2D::Vector2D(const Vector2D& ano) {
    this->x = ano.x;
    this->y = ano.y;
}
Vector2D::Vector2D(const double module, const double angle){
    double normal_angle = angle - M_PI/2;
    x = module * cos(normal_angle);
    y = module * sin(normal_angle);
}

Vector2D::Vector2D(const double module, const Vector2D& direction){
    Vector2D normal_direction = direction.getDirection();
    x = module * normal_direction.getX();
    y = module * normal_direction.getY();
}

Vector2D::Vector2D(const Point2D& start, const Point2D& end){
    x = end.getX() - start.getX();
    y = end.getY() - start.getY();
}

double Vector2D::getX() const{
    return x;
}

double Vector2D::getY() const{
    return y;
}

Vector2D Vector2D::plus(const Vector2D& ano) const{
    return Vector2D(x + ano.x, y + ano.y);
}

Vector2D Vector2D::minus(const Vector2D& ano) const{
    return Vector2D(x - ano.x, y - ano.y);
}

double Vector2D::multiply(const Vector2D& ano) const{
    return x*ano.x + y*ano.y;
}

Vector2D Vector2D::multiply(const double lambda) const{
    return Vector2D(lambda * x, lambda * y);
}

Vector2D Vector2D::reverse() const{
    return multiply(-1);
}

Vector2D Vector2D::getDirection() const{
    double mod = getModule();
    if(mod == 0.0) return Vector2D();
    else return multiply(1 / mod);
}

double Vector2D::getModule() const{
    return sqrt(x*x + y*y);
}

double Vector2D::getCosineWith(const Vector2D& ano) const{
    double mul = multiply(ano);
    if(mul == 0.0) return 0;
    else return mul/getModule()/ano.getModule();
}

Vector2D Vector2D::rotate(const double rad) const{
    return Vector2D(sin(rad)*y + cos(rad)*x, cos(rad)*y - sin(rad)*x);
}
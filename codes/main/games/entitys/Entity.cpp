/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Entity.h"
#define EPS 1e-6
#include <cmath>
using std::abs, std::sqrt, std::acos;

/**
 * Entity implementation
 * 
 * 实体类
 */


Entity::Entity(double radius, Entity* parentEntity, double x, double y) {
    this->radius = radius;
    this->parentEntity = parentEntity;
    this->x = x;
    this->y = y;
}

Entity* Entity::getParentEntity() const{
    return parentEntity;
}

double Entity::getX() const{
    return x;
}

void Entity::setX(const double x) {
    this->x = x;
}

double Entity::getY() const{
    return y;
}

void Entity::setY(const double y) {
    this->y = y;
}

double Entity::getRadius() const{
    return radius;
}

bool Entity::isTangency(const Entity& ano) const{
    return abs(getDistance(ano) - (radius+ano.radius)) < EPS;
}

bool Entity::isInscribed(const Entity& ano) const{
    return abs(getDistance(ano) - abs(radius - ano.radius)) < EPS;
}

bool Entity::isOverlapped(const Entity& ano) const{
    return isInscribed(ano) || isTangency(ano) || (getDistance(ano) <= (radius+ano.radius) && !isContained(ano) && !contains(ano));
}

bool Entity::isContained(const Entity& ano) const{
    return !isInscribed(ano) && (getDistance(ano) + radius) < ano.radius;
}

bool Entity::isDisjointed(const Entity& ano) const{
    return !isInscribed(ano) && !isTangency(ano) && getDistance(ano) > (radius+ano.radius);
}

bool Entity::contains(const Entity& ano) const{
    return !isInscribed(ano) && (getDistance(ano) + ano.radius) < radius;
}

double Entity::getDistance(const Entity& ano) const{
    double deltax = abs(x - ano.x);
    double deltay = abs(y - ano.y);
    return sqrt(deltax*deltax + deltay*deltay);
}

double Entity::getRelativeAngle(const Entity& ano) const{
    return acos(Vector2D(x, y+1).getCosineWith(toVector2D(ano)));
}

Vector2D Entity::toVector2D(const Entity& ano) const{
    return Vector2D(ano.x - x, ano.y - y);
}

string Entity::toString() const{
    return "";
}

Entity::~Entity() {

}
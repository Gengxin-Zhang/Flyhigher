/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "MovableEntity.h"
#define PI 3.141592653589793

/**
 * MovableEntity implementation
 */

MovableEntity::MovableEntity(const double radius, const Vector2D speed,
 Entity* const parentEntity, const double x, const double y): Entity(radius, parentEntity, x, y) {
        this->speed = Vector2D(speed);
}

Vector2D MovableEntity::getSpeed() const{
    return speed;
}

void MovableEntity::turnDirection(const double rad) {
    if(rad < -PI/24 || rad > PI/24) return;
    speed = speed.rotate(rad);
}

void MovableEntity::goNextTick() {
    setX(getX() + speed.getX());
    setY(getY() + speed.getY());
}

MovableEntity::~MovableEntity() {

}
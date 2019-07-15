/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "MovableEntity.h"
#include <cmath>

/**
 * MovableEntity implementation
 */

MovableEntity::MovableEntity(const double radius, const Vector2D speed,
 Entity* const parentEntity, const double x, const double y): Entity(radius, parentEntity, x, y) {
        this->speed = Vector2D(speed);
        this->moving = false;
}

Vector2D MovableEntity::getSpeed() const{
    return speed;
}

void MovableEntity::turnDirection(const double rad) {
//    if(rad < -M_PI/24 || rad > M_PI/24) return;
    speed = speed.rotate(rad);
}

void MovableEntity::goNextTick() {
    setX(getX() + speed.getX());
    setY(getY() + speed.getY());
}

bool MovableEntity::isMoving() const {
    return moving;
}

void MovableEntity::setMoving(const bool moving) {
    this->moving = moving;
}

MovableEntity::~MovableEntity() {

}

string MovableEntity::getClassName() const{
    return "MovableEntity";
}

string MovableEntity::toString() const{
    return Entity::toString() + "[MovableEntity] (speed=" + speed.toString() + ")";
}

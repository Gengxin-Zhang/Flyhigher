/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Nuke.h"

/**
 * Nuke implementation
 */

bool Nuke::hasShoot() const{
    return shoot;
}

int Nuke::getAoeDamage() const{
    return aoeDamage;
}

double Nuke::getAoeDamageRadius() const{
    return aoeDamageRadius;
}

int Nuke::getDamageDecrease() const{
    return damageDecrease;
}

double Nuke::getRadius() const{
    return radius;
}

int Nuke::getSpeed() const{
    return speed;
}

bool Nuke::shoot(const double direction) const{
    //TODO: 想想怎么做
}

Nuke::Nuke(const int aoeDamage, const double aoeDamageRadius, const int damageDecrease, const double radius, const int speed) {
    this->aoeDamage = aoeDamage;
    this->aoeDamageRadius = aoeDamageRadius;
    this->damageDecrease = damageDecrease;
    this->radius =radius;
    this->speed = speed;
}

Nuke::~Nuke() {

}
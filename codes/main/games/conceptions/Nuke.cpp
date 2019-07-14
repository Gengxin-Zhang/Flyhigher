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
    return shooted;
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

Nuke::Nuke(NukeConfiguration* const config) {
    aoeDamage = config->getAoeDamage();
    aoeDamageRadius = config->getAoeDamageRadius();
    damageDecrease = config->getDamageDecrease();
    radius = config->getRadius();
    speed = config->getSpeed();
}

Nuke::~Nuke() {

}

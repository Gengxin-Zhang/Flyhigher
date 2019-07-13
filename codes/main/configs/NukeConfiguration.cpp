/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "NukeConfiguration.h"

/**
 * NukeConfiguration implementation
 */

int NukeConfiguration::getAoeDamage() const{
    return aoeDamage;
}

double NukeConfiguration::getAoeDamageRadius() const{
    return aoeDamageRadius;
}

int NukeConfiguration::getDamageDecrease() const{
    return damageDecrease;
}

double NukeConfiguration::getRadius() const{
    return radius;
}

int NukeConfiguration::getSpeed() const{
    return speed;
}

NukeConfiguration::NukeConfiguration(const int aoeDamage, const double aoeDamageRadius,
 const int damageDecrease, const double radius, const int speed) {
    this->aoeDamage = aoeDamage;
    this->aoeDamageRadius = aoeDamageRadius;
    this-> damageDecrease = damageDecrease;
    this->radius = radius;
    this->speed = speed;
}

NukeConfiguration::~NukeConfiguration() {

}
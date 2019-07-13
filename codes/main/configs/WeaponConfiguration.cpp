/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "WeaponConfiguration.h"

/**
 * WeaponConfiguration implementation
 */

double WeaponConfiguration::getRadius() const{
    return radius;
}

int WeaponConfiguration::getDamage() const{
    return damage;
}

int WeaponConfiguration::getSpeed() const{
    return speed;
}

int WeaponConfiguration::getDelay() const{
    return delay;
}

WeaponConfiguration::WeaponConfiguration(const double radius, const double damage, const int speed, const int delay) {
    this->radius = radius;
    this->damage =damage;
    this->speed =speed;
    this->delay = delay;
}

WeaponConfiguration::~WeaponConfiguration() {

}
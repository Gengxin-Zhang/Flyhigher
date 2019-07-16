/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Weapon.h"

/**
 * Weapon implementation
 * 
 * 武器类
 */

Weapon::Weapon(shared_ptr<WeaponConfiguration> const config) {
    radius = config->getRadius();
    damage = config->getDamage();
    speed = config->getSpeed();
    delay = config->getDelay();
    lastShoot = 0; 
}

Weapon::~Weapon() {

}

bool Weapon::shoot(const double direction) const{
    //TODO: 当前tick - lastShoot < delay
    if (lastShoot < delay){
        return false;
    }
    //TODO: lastShoot设置为当前tick
    //TODO: 射击
    return true;
}

double Weapon::getRadius() const{
    return radius;
}

double Weapon::getDamage() const{
    return damage;
}

int Weapon::getSpeed() const{
    return speed;
}

int Weapon::getDelay() const{
    return delay;
}

long Weapon::getLastShoot() const{
    return lastShoot;
}

/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Weapon.h"
#include "../../systems/Engine.h"

#define loop Engine::getInstance()->getNowGame()->getLoop()
#define log Engine::getInstance()->getLogger()

/**
 * Weapon implementation
 * 
 * 武器类
 */

Weapon::Weapon(shared_ptr<WeaponConfiguration> const config, shared_ptr<Entity> const parentEntity) {
    radius = config->getRadius();
    damage = config->getDamage();
    speed = config->getSpeed();
    delay = config->getDelay();
    lastShoot = 0; 
    this->parentEntity = parentEntity;
}

Weapon::~Weapon() {

}

bool Weapon::shoot(const double direction){
    if (loop->getNowTick() - lastShoot < delay){
        return false;
    }
    lastShoot  = loop->getNowTick();
    shared_ptr<Bullet> bullet(new Bullet(radius, Vector2D(speed, direction, true),
                                         damage, parentEntity, parentEntity->getX(), parentEntity->getY()));
    log->debug(bullet->toString() + "被射出");
    loop->addBullet(bullet);
    return true;
}

double Weapon::getRadius() const{
    return radius;
}

int Weapon::getDamage() const{
    return damage;
}

double Weapon::getSpeed() const{
    return speed;
}

int Weapon::getDelay() const{
    return delay;
}

long Weapon::getLastShoot() const{
    return lastShoot;
}

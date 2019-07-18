/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Nuke.h"
#include "../../systems/Engine.h"

#define loop Engine::getInstance()->getNowGame()->getLoop()
#define log Engine::getInstance()->getLogger()

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

double Nuke::getSpeed() const{
    return speed;
}

bool Nuke::shoot(const double direction){
    if (shooted){
        return false;
    }
    shooted = true;
    shared_ptr<Bullet> bullet(new Bullet(radius, Vector2D(speed, direction, true),
                                         aoeDamage, parentEntity, parentEntity->getX(), parentEntity->getY()));
    log->debug(bullet->toString() + "被射出");
    loop->addBullet(bullet);
    return true;
}

Nuke::Nuke(shared_ptr<NukeConfiguration> const config, shared_ptr<Entity> const parentEntity) {
    aoeDamage = config->getAoeDamage();
    aoeDamageRadius = config->getAoeDamageRadius();
    damageDecrease = config->getDamageDecrease();
    radius = config->getRadius();
    speed = config->getSpeed();
    this->parentEntity = parentEntity;
    shooted = false;
}

Nuke::~Nuke() {

}

/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Carrier.h"
#include <vector>
#include <cmath>
using std::vector, std::cos;
#include "../../systems/Engine.h"
#define loop Engine::getInstance()->getNowGame()->getLoop()

/**
 * Carrier implementation
 * 
 * 母舰类
 */

Carrier::Carrier(shared_ptr<Player> const player,
                 shared_ptr<CarrierConfiguration> const config,
                 shared_ptr<Entity> const parentEntity, const double x, const double y):
                 LivingEntity(player, config->getConfig(), parentEntity, x, y) {
    this->config = config;

}

void Carrier::init(){
    LivingEntity::init();
    mainWeapon =  shared_ptr<Weapon>(new Weapon(config->getWeaponConfig(), shared_from_this()));
    godWeapon = shared_ptr<Nuke>(new Nuke(config->getNukeConfig(), shared_from_this()));
}

Carrier::~Carrier() {
}

bool Carrier::isInSight(const Entity& ano) const{
    if(isMoving()){
        if(getSpeed().getCosineWith(toVector2D(ano)) > 0 && getSpeed().getCosineWith(toVector2D(ano)) < cos(sightAngle)){
                return getDistance(ano) <= longSight;
        }
    }else{
        return getDistance(ano) <= shortSight;
    }
}

bool Carrier::shoot(const double direction) const{
    return mainWeapon->shoot(direction);
}

bool Carrier::shootGodWeapon(const double direction) const{
    return godWeapon->shoot(direction);
}

bool Carrier::getNukeShooted() const {
    return godWeapon->hasShoot();
}

string Carrier::getClassName() const{
    return "Carrier";
}

string Carrier::toString() const{
    return LivingEntity::toString() +"[Carrier] ()";
}

int Carrier::getWeaponCD() const{
    return mainWeapon->getDelay() - (loop->getNowTick() - mainWeapon->getLastShoot());
}

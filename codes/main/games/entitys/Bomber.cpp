/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Bomber.h"
#include <vector>
#include "../../systems/Engine.h"
#include <cmath>
#define loop Engine::getInstance()->getNowGame()->getLoop()
using std::vector, std::cos;

/**
 * Bomber implementation
 */


Bomber::Bomber(shared_ptr<Player> const player,
               shared_ptr<BomberConfiguration> const config,
               shared_ptr<Entity> const parentEntity, const double x, const double y):
               LivingEntity(player, config->getConfig(), parentEntity, x, y)  {
     this->config = config;
}

Bomber::~Bomber() {
}

void Bomber::init(){
    LivingEntity::init();
    weapon = shared_ptr<Weapon>(new Weapon(config->getWeaponConfig(), shared_from_this()));
}

bool Bomber::isInSight(const Entity& ano) const{
    if(isMoving()){
        if(getSpeed().getCosineWith(toVector2D(ano)) > 0 && getSpeed().getCosineWith(toVector2D(ano)) < cos(sightAngle)){
                return getDistance(ano) <= longSight;
        }else{
            return false;
        }
    }else{
        return getDistance(ano) <= shortSight;
    }
}

bool Bomber::shoot(const double direction) const{
    return weapon->shoot(direction);
}

string Bomber::getClassName() const{
    return "Bomber";
}

string Bomber::toString() const{
    return LivingEntity::toString() +"[Bomber] ()";
}

int Bomber::getWeaponCD() const{
    return weapon->getDelay() - (loop->getNowTick() - weapon->getLastShoot());
}

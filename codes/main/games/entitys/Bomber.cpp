/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Bomber.h"

/**
 * Bomber implementation
 */


Bomber::Bomber(Player* const player, BomberConfiguration* const config, Entity* const parentEntity, const double x, const double y):
 LivingEntity(player, config->getConfig(), parentEntity, x, y)  {
     weapon = new Weapon(config->getWeaponConfig());
}

Bomber::~Bomber() {
    delete [] weapon;
}

vector<Entity*> Bomber::see() const{
    //TODO: 思考怎么实现ing
}

bool Bomber::isInSight(const Entity& ano) const{
    //TODO: 思考怎么实现ing
}

bool Bomber::shoot(const double direction) const{
    return weapon->shoot(direction);
}
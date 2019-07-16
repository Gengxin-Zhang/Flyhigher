/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Bomber.h"
#include <vector>
using std::vector;

/**
 * Bomber implementation
 */


Bomber::Bomber(shared_ptr<Player> const player,
               shared_ptr<BomberConfiguration> const config,
               shared_ptr<Entity> const parentEntity, const double x, const double y):
               LivingEntity(player, config->getConfig(), parentEntity, x, y)  {
     weapon = shared_ptr<Weapon>(new Weapon(config->getWeaponConfig()));
}

Bomber::~Bomber() {
}

vector<shared_ptr<Entity>> Bomber::see() const{
    //TODO: 思考怎么实现ing
}

bool Bomber::isInSight(const Entity& ano) const{
    //TODO: 思考怎么实现ing
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

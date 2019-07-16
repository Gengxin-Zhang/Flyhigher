/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Carrier.h"
#include <vector>
using std::vector;

/**
 * Carrier implementation
 * 
 * 母舰类
 */

Carrier::Carrier(shared_ptr<Player> const player,
                 shared_ptr<CarrierConfiguration> const config,
                 shared_ptr<Entity> const parentEntity, const double x, const double y):
                 LivingEntity(player, config->getConfig(), parentEntity, x, y) {
    mainWeapon =  shared_ptr<Weapon>(new Weapon(config->getWeaponConfig()));
    godWeapon = shared_ptr<Nuke>(new Nuke(config->getNukeConfig()));
}

Carrier::~Carrier() {
}

vector<shared_ptr<Entity>> Carrier::see() const{
    //TODO: 思考怎么实现ing
}

bool Carrier::isInSight(const Entity& ano) const{
    //TODO: 思考怎么实现ing
}

bool Carrier::shoot(const double direction) const{
    return mainWeapon->shoot(direction);
}

bool Carrier::shootGodWeapon(const double direction) const{
    return godWeapon->shoot(direction);
}

string Carrier::getClassName() const{
    return "Carrier";
}

string Carrier::toString() const{
    return LivingEntity::toString() +"[Carrier] ()";
}

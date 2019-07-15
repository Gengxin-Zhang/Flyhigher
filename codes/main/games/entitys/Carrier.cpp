/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Carrier.h"

/**
 * Carrier implementation
 * 
 * 母舰类
 */

Carrier::Carrier(shared_ptr<Player> const player, CarrierConfiguration* const config, shared_ptr<Entity> const parentEntity, const double x, const double y):
 LivingEntity(player, config->getConfig(), parentEntity, x, y) {
    mainWeapon = new Weapon(config->getWeaponConfig());
    godWeapon = new Nuke(config->getNukeConfig());
}

Carrier::~Carrier() {
    delete mainWeapon;
    delete godWeapon;
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

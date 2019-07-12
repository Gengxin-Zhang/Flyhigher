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

Carrier::Carrier(Player* const player, const CarrierConfiguration& config, Entity* const parentEntity, const double x, const double y):
 LivingEntity(player, config.getCarrierRadius(), config.getMaxHealth(), Vector2D(0, config.getSpeed()), parentEntity, x, y) {
    this->config = config;
    //TODO: 通过配置项调用父类构造函数
    //TODO: 通过配置项构造mainWeapon
    //TODO: 通过配置项构造godWeapon
}

Carrier::~Carrier() {

}

vector<Entity*> Carrier::see() const{
    //TODO: 思考怎么实现ing
}

bool Carrier::isInSight(const Entity& ano) const{
    //TODO: 思考怎么实现ing
}

bool Carrier::shoot(const double direction) const{
    return mainWeapon.shoot(direction);
}

bool Carrier::shootGodWeapon(const double direction) const{
    return godWeapon.shoot(direction);
}
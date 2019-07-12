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

Carrier::Carrier(const CarrierConfiguration& config) {
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
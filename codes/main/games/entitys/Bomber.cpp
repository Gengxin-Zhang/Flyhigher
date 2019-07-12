/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Bomber.h"

/**
 * Bomber implementation
 */


Bomber::Bomber(const BomberConfiguration& config) {
    this->config = config;
}

Bomber::~Bomber() {

}

vector<Entity*> Bomber::see() const{
    //TODO: 思考怎么实现ing
}

bool Bomber::isInSight(const Entity& ano) const{
    //TODO: 思考怎么实现ing
}

bool Bomber::shoot(const double direction) const{
    return weapon.shoot(direction);
}
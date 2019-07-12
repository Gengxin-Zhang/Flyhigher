/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Bomber.h"

/**
 * Bomber implementation
 */


Bomber::Bomber(Player* const player, const BomberConfiguration& config, Entity* const parentEntity, const double x, const double y):
 LivingEntity(player, config.getBomberRadius(), config.getMaxHealth(), Vector2D(0, config.getSpeed()), parentEntity, x, y)  {
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
/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "LivingEntity.h"
#include "../Player.h"

/**
 * LivingEntity implementation
 */


LivingEntity::LivingEntity(Player* const player, PlaneConfiguration* const config,
 Entity* const parentEntity, const double x, const double y)
 :MovableEntity(config->getRadius(), Vector2D(0, config->getSpeed()), parentEntity, x, y) {
     this->player = player;
     maxHealth = config->getMaxHealth();
     healRate = config->getHealRate();
     healPower = config->getHealPower();
     this->nowHealth = 0;
}

int LivingEntity::getMaxHealth() const{
    return maxHealth;
}

int LivingEntity::getNowHealth() const{
    return nowHealth;
}

void LivingEntity::heal(const int health) {
    nowHealth += health;
    if(nowHealth > maxHealth) nowHealth = maxHealth;
}

void LivingEntity::damage(const int damage) {
    nowHealth -= damage;
    if(nowHealth < 0) die();
}

void LivingEntity::init() {
    nowHealth = maxHealth;
    //TODO: 实体库中添加此实体
}

void LivingEntity::die() {
    //TODO: 实体库中删除此实体
}

Player* LivingEntity::getPlayer() const{
    return player;
}

int LivingEntity::getHealRate() const{
    return healRate;
}

int LivingEntity::getHealPower() const{
    return healPower;
}

LivingEntity::~LivingEntity() {

}

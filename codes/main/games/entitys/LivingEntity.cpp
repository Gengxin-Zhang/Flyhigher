/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "LivingEntity.h"

/**
 * LivingEntity implementation
 */


LivingEntity::LivingEntity(const double radius, const int maxHealth, const Vector2D speed,
 Entity* const parentEntity, const double x, const double y): MovableEntity(radius, speed, parentEntity, x, y) {
     this->maxHealth = maxHealth;
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
    delete this;
}

LivingEntity::~LivingEntity() {

}
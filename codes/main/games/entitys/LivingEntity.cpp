/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "LivingEntity.h"

/**
 * LivingEntity implementation
 */


/**
 * @param parentEntity
 * @param x
 * @param y
 * @param radius
 * @param maxHealth
 */
void LivingEntity::LivingEntity(Entity parentEntity, double x, double y, double radius, int maxHealth) {

}

/**
 * @return int
 */
int LivingEntity::getMaxHealth() {
    return 0;
}

/**
 * @return int
 */
int LivingEntity::getNowHealth() {
    return 0;
}

/**
 * @param health
 * @return void
 */
void LivingEntity::heal(int health) {
    return;
}

/**
 * @param damage
 * @return void
 */
void LivingEntity::damage(int damage) {
    return;
}

/**
 * 出生
 * @return void
 */
virtual void LivingEntity::init() {
    return;
}

/**
 * 消亡
 * @return void
 */
virtual void LivingEntity::die() {
    return;
}

/**
 * 析构函数
 */
void LivingEntity::~LivingEntity() {

}

/**
 * 视野内的所有实体
 * @return vector<Entity>
 */
virtual vector<Entity> LivingEntity::see() {
    return null;
}

/**
 * 判断实体是否在视野内
 * @param ano
 * @return bool
 */
virtual bool LivingEntity::isInSight(Entity ano) {
    return false;
}

/**
 * @param direction
 * @return bool
 */
virtual bool LivingEntity::shoot(double direction) {
    return false;
}
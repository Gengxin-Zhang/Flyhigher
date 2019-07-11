/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "MovableEntity.h"

/**
 * MovableEntity implementation
 */


/**
 * 构造函数
 * @param parentEntity
 * @param x
 * @param y
 * @param radius
 */
void MovableEntity::MovableEntity(Entity parentEntity, double x, double y, double radius) {

}

/**
 * 获取速度向量
 * @return Vector2D
 */
Vector2D MovableEntity::getSpeed() {
    return null;
}

/**
 * 改变速度向量的方向，弧度制，每次改变不能超过绝对值pai/24
 * @param rad
 * @return void
 */
void MovableEntity::turnDirection(double rad) {
    return;
}

/**
 * 向当前速度向量的位置移动，时间是1tick。
 * @return void
 */
void MovableEntity::goNextTick() {
    return;
}

/**
 * 析构函数
 */
void MovableEntity::~MovableEntity() {

}
/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Fighter.h"

/**
 * Fighter implementation
 */


/**
 * 构造函数
 * @param config
 */
void Fighter::Fighter(FighterConfiguration config) {

}

/**
 * 析构函数
 */
void Fighter::~Fighter() {

}

/**
 * 初始化
 * @return void
 */
void Fighter::init() {
    return;
}

/**
 * 死去
 * @return void
 */
void Fighter::die() {
    return;
}

/**
 * 获取视野内的实体
 * @return vector<Entity>
 */
vector<Entity> Fighter::see() {
    return null;
}

/**
 * 判断实体是否位于视野内
 * @param ano
 * @return bool
 */
bool Fighter::isInSight(Entity ano) {
    return false;
}

/**
 * 射击
 * @param direction
 * @return bool
 */
bool Fighter::shoot(double direction) {
    return false;
}

/**
 * 是否处于采集状态
 * @return bool
 */
bool Fighter::isCollecting() {
    return false;
}

/**
 * 采集资源实体
 * @param entity
 * @return void
 */
void Fighter::collect(ResourceEntity entity) {
    return;
}

/**
 * @return void
 */
void Fighter::collectCompletely() {
    return;
}

/**
 * @return void
 */
void Fighter::stopCollecting() {
    return;
}
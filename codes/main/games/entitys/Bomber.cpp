/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Bomber.h"

/**
 * Bomber implementation
 */


/**
 * 构造函数
 * @param config
 */
void Bomber::Bomber(BomberConfiguration config) {

}

/**
 * 析构函数
 */
void Bomber::~Bomber() {

}

/**
 * 初始化
 * @return void
 */
void Bomber::init() {
    return;
}

/**
 * 死去
 * @return void
 */
void Bomber::die() {
    return;
}

/**
 * 获得视野内的对象
 * @return vector<Entity>
 */
vector<Entity> Bomber::see() {
    return null;
}

/**
 * 实体是否位于视野中
 * @param ano
 * @return bool
 */
bool Bomber::isInSight(Entity ano) {
    return false;
}

/**
 * 射击
 * @param direction
 * @return bool
 */
bool Bomber::shoot(double direction) {
    return false;
}
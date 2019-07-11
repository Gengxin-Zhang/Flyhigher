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


/**
 * 构造函数
 * @param config
 */
void Carrier::Carrier(CarrierConfiguration config) {

}

/**
 * 析构函数
 */
void Carrier::~Carrier() {

}

/**
 * 初始化状态
 * @return void
 */
void Carrier::init() {
    return;
}

/**
 * 死去
 * @return void
 */
void Carrier::die() {
    return;
}

/**
 * 视野内的实体
 * @return vector<Entity>
 */
vector<Entity> Carrier::see() {
    return null;
}

/**
 * 判断实体是否在视野内
 * @param ano
 * @return bool
 */
bool Carrier::isInSight(Entity ano) {
    return false;
}

/**
 * 射击
 * @param direction
 * @return bool
 */
bool Carrier::shoot(double direction) {
    return false;
}

/**
 * 发射必杀武器
 * @param direction
 * @return bool
 */
bool Carrier::shootGodWeapon(double direction) {
    return false;
}
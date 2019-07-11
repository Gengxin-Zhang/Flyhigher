/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "ResourceEntity.h"

/**
 * ResourceEntity implementation
 */


/**
 * 构造函数
 * @param parentEntity
 * @param x
 * @param y
 * @param radius
 * @param power
 */
void ResourceEntity::ResourceEntity(Entity parentEntity, double x, double y, double radius, int power) {

}

/**
 * 获取资源量
 * @return int
 */
int ResourceEntity::getPower() {
    return 0;
}

/**
 * 析构函数
 */
void ResourceEntity::~ResourceEntity() {

}

/**
 * 设置是否被采集
 * @param bool being
 * @return void
 */
void ResourceEntity::setBeingCollected(void bool being) {
    return;
}

/**
 * 是否正在被采集
 * @return bool
 */
bool ResourceEntity::isBeingCollected() {
    return false;
}
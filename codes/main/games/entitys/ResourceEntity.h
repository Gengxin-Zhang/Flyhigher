/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _RESOURCEENTITY_H
#define _RESOURCEENTITY_H

#include "Entity.h"


class ResourceEntity: public Entity {
public: 
    
/**
 * 构造函数
 * @param parentEntity
 * @param x
 * @param y
 * @param radius
 * @param power
 */
void ResourceEntity(Entity parentEntity, double x, double y, double radius, int power);
    
/**
 * 获取资源量
 */
int getPower();
    
/**
 * 析构函数
 */
void ~ResourceEntity();
    
/**
 * 设置是否被采集
 * @param bool being
 */
void setBeingCollected(void bool being);
    
/**
 * 是否正在被采集
 */
bool isBeingCollected();
private: 
    /**
 * 这个资源实体具有的资源量
 */
int power;
    /**
 * 是否正在被采集
 */
bool beingCollected;
};

#endif //_RESOURCEENTITY_H
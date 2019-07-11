/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _MOVABLEENTITY_H
#define _MOVABLEENTITY_H

#include "Entity.h"
#include "LivingEntity.h"
#include "Entity.h"


class MovableEntity: public Entity, public LivingEntity, public Entity {
public: 
    
/**
 * 构造函数
 * @param parentEntity
 * @param x
 * @param y
 * @param radius
 */
void MovableEntity(Entity parentEntity, double x, double y, double radius);
    
/**
 * 获取速度向量
 */
Vector2D getSpeed();
    
/**
 * 改变速度向量的方向，弧度制，每次改变不能超过绝对值pai/24
 * @param rad
 */
void turnDirection(double rad);
    
/**
 * 向当前速度向量的位置移动，时间是1tick。
 */
void goNextTick();
    
/**
 * 析构函数
 */
void ~MovableEntity();
private: 
    /**
 * 速度向量
 */
Vector2D speed;
};

#endif //_MOVABLEENTITY_H
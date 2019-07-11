/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _BULLET_H
#define _BULLET_H

#include "MovableEntity.h"
#include "../conceptions/Damageable.h"


class Bullet: public MovableEntity, public Damageable {
public: 
    
/**
 * 构造函数
 * @param parentEntity
 * @param x
 * @param y
 * @param radius
 * @param speed
 * @param damage
 */
void Bullet(Entity parentEntity, double x, double y, double radius, Vector2D speed, int damage);
    
/**
 * 获取击中实体造成的伤害值
 */
int getDamage();
    
/**
 * 对一个实体造成伤害
 * @param entity LivingEntity
 */
void damageTo(void entity LivingEntity);
    
/**
 * 析构函数
 */
void ~Bullet();
private: 
    /**
 * 子弹击中造成的伤害
 */
int damage;
};

#endif //_BULLET_H
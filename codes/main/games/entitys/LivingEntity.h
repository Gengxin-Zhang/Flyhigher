/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _LIVINGENTITY_H
#define _LIVINGENTITY_H

#include "MovableEntity.h"
#include "MovableEntity.h"
#include "MovableEntity.h"


class LivingEntity: public MovableEntity, public MovableEntity, public MovableEntity {
public: 
    
/**
 * @param parentEntity
 * @param x
 * @param y
 * @param radius
 * @param maxHealth
 */
void LivingEntity(Entity parentEntity, double x, double y, double radius, int maxHealth);
    
int getMaxHealth();
    
int getNowHealth();
    
/**
 * @param health
 */
void heal(int health);
    
/**
 * @param damage
 */
void damage(int damage);
    
/**
 * 出生
 */
virtual void init() = 0;
    
/**
 * 消亡
 */
virtual void die() = 0;
    
/**
 * 析构函数
 */
void ~LivingEntity();
    
/**
 * 视野内的所有实体
 */
virtual vector<Entity> see() = 0;
    
/**
 * 判断实体是否在视野内
 * @param ano
 */
virtual bool isInSight(Entity ano) = 0;
    
/**
 * @param direction
 */
virtual bool shoot(double direction) = 0;
private: 
    /**
 * 当前状态的生命值
 */
int nowHealth;
    /**
 * 最大生命值
 */
int maxHealth;
};

#endif //_LIVINGENTITY_H
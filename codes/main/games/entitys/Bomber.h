/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _BOMBER_H
#define _BOMBER_H

#include "LivingEntity.h"


class Bomber: public LivingEntity {
public: 
    
/**
 * 构造函数
 * @param config
 */
void Bomber(BomberConfiguration config);
    
/**
 * 析构函数
 */
void ~Bomber();
    
/**
 * 初始化
 */
void init();
    
/**
 * 死去
 */
void die();
    
/**
 * 获得视野内的对象
 */
vector<Entity> see();
    
/**
 * 实体是否位于视野中
 * @param ano
 */
bool isInSight(Entity ano);
    
/**
 * 射击
 * @param direction
 */
bool shoot(double direction);
private: 
    /**
 * 武器
 */
Weapon weapon;
    /**
 * 轰炸机配置项
 */
BomberConfiguration config;
};

#endif //_BOMBER_H
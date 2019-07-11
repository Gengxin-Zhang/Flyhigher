/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _FIGHTER_H
#define _FIGHTER_H

#include "LivingEntity.h"


class Fighter: public LivingEntity {
public: 
    ResourceEntity collectingEntity;
    
/**
 * 构造函数
 * @param config
 */
void Fighter(FighterConfiguration config);
    
/**
 * 析构函数
 */
void ~Fighter();
    
/**
 * 初始化
 */
void init();
    
/**
 * 死去
 */
void die();
    
/**
 * 获取视野内的实体
 */
vector<Entity> see();
    
/**
 * 判断实体是否位于视野内
 * @param ano
 */
bool isInSight(Entity ano);
    
/**
 * 射击
 * @param direction
 */
bool shoot(double direction);
    
/**
 * 是否处于采集状态
 */
bool isCollecting();
    
/**
 * 采集资源实体
 * @param entity
 */
void collect(ResourceEntity entity);
    
void collectCompletely();
    
void stopCollecting();
private: 
    /**
 * 武器
 */
Weapon weapon;
    /**
 * 战斗机配置项
 */
FighterConfiguration config;
    /**
 * 是否处于采集状态
 */
bool isCollecting;
};

#endif //_FIGHTER_H
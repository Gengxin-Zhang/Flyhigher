/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _CARRIER_H
#define _CARRIER_H

#include "MovableEntity.h"
#include "LivingEntity.h"


class Carrier: public MovableEntity, public LivingEntity {
public: 
    /**
 * 母舰类配置项
 */
CarrierConfiguration config;
    
/**
 * 构造函数
 * @param config
 */
void Carrier(CarrierConfiguration config);
    
/**
 * 析构函数
 */
void ~Carrier();
    
/**
 * 初始化状态
 */
void init();
    
/**
 * 死去
 */
void die();
    
/**
 * 视野内的实体
 */
vector<Entity> see();
    
/**
 * 判断实体是否在视野内
 * @param ano
 */
bool isInSight(Entity ano);
    
/**
 * 射击
 * @param direction
 */
bool shoot(double direction);
    
/**
 * 发射必杀武器
 * @param direction
 */
bool shootGodWeapon(double direction);
private: 
    /**
 * 主武器
 */
Weapon mainWeapon;
    /**
 * 必杀武器，只能使用一次
 */
Weapon godWeapon;
};

#endif //_CARRIER_H
/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _CARRIER_H
#define _CARRIER_H

#include "LivingEntity.h"
#include "../../configs/CarrierConfiguration.h"


class Carrier: public LivingEntity {
    public:
        /**
         * 构造函数
         * @param config 母舰配置项
         */
        Carrier(Player* const player, const CarrierConfiguration& config,
         Entity* const parentEntity = (Entity*)0, const double x = 0, const double y = 0);
            
        /**
         * 析构函数
         */
        ~Carrier();
         
        /**
         * 视野内的实体
         */
        vector<Entity*> see() const;
            
        /**
         * 判断实体是否在视野内
         * @param ano 实体
         */
        bool isInSight(const Entity& ano) const;
            
        /**
         * 射击
         * @param direction 方向，以y轴正半轴为0，逆时针为正，弧度制
         */
        bool shoot(const double direction) const;
            
        /**
         * 发射必杀武器
         * @param direction 方向，以y轴正半轴为0，逆时针为正，弧度制
         */
        bool shootGodWeapon(const  double direction) const;
    private:
        //主武器
        Weapon mainWeapon;
        //必杀武器，只能使用一次
        Weapon godWeapon;
        //母舰配置项
        CarrierConfiguration config;
};

#endif //_CARRIER_H
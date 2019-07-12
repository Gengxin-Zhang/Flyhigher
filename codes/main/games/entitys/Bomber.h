/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _BOMBER_H
#define _BOMBER_H

#include "LivingEntity.h"
#include "../../configs/BomberConfiguration.h"


class Bomber: public LivingEntity {
    public: 
        /**
         * 构造函数
         * @param config 轰炸机配置项
         */
        Bomber(Player* const player, const BomberConfiguration& config,
         Entity* const parentEntity = (Entity*)0, const double x = 0, const double y = 0);
            
        /**
         * 析构函数
         */
        ~Bomber();
            
        /**
         * 获得视野内的对象
         */
        vector<Entity*> see() const;
            
        /**
         * 实体是否位于视野中
         * @param ano 实体
         */
        bool isInSight(const Entity& ano) const;
            
        /**
         * 射击
         * @param direction 方向，以y轴正半轴为0，逆时针为正，弧度制
         */
        bool shoot(const double direction) const;
    private: 
        //武器
        Weapon weapon;
        //轰炸机配置项
        BomberConfiguration config;
};

#endif //_BOMBER_H
/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _BOMBER_H
#define _BOMBER_H

#include "LivingEntity.h"
#include "../../configs/BomberConfiguration.h"
#include "../conceptions/Weapon.h"

class Player;

class Bomber: public LivingEntity {
    public: 
        /**
         * 构造函数
         * @param player 所属玩家方
         * @param config 轰炸机配置项
         * @param parentEntity 父实体
         * @param x x坐标
         * @param y y坐标
         */
        Bomber(Player* const player, BomberConfiguration* const config,
         Entity* const parentEntity = nullptr, const double x = 0, const double y = 0);
            
        /**
         * 析构函数
         */
        ~Bomber();
            
        /**
         * 获得视野内的对象
         */
        virtual vector<Entity*> see() const;
            
        /**
         * 实体是否位于视野中
         * @param ano 实体
         */
        virtual bool isInSight(const Entity& ano) const;
            
        /**
         * 射击
         * @param direction 方向，以y轴正半轴为0，逆时针为正，弧度制
         */
        virtual bool shoot(const double direction) const;

        /**
         * 获取类型名称
         * @return 类型名称
         */
        virtual string getClassName() const;

        /**
         * 将实体以字符串显示
         * @return 字符串
         */
        virtual string toString() const;
    private: 
        //武器
        Weapon* weapon;
};

#endif //_BOMBER_H

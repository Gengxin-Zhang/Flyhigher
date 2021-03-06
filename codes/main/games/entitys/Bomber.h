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
using std::enable_shared_from_this;

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
        Bomber(shared_ptr<Player> const player, shared_ptr<BomberConfiguration> const config,
         shared_ptr<Entity> const parentEntity = nullptr, const double x = 0, const double y = 0);
            
        /**
         * 析构函数
         */
        ~Bomber();
            
            
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
         * 距离下一次射击还有多久冷却时间
         * @return 冷却时间
         */
        virtual int getWeaponCD() const;

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

        /**
         * 初始化行为
         */
        virtual void init();

    private: 
        //武器
        shared_ptr<Weapon> weapon;
        shared_ptr<BomberConfiguration> config;
        double sightAngle;
        double longSight;
        double shortSight;
};

#endif //_BOMBER_H

/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _FIGHTER_H
#define _FIGHTER_H

#include "LivingEntity.h"
#include "ResourceEntity.h"
#include "../../configs/FighterConfiguration.h"
#include "../conceptions/Weapon.h"


class Fighter: public LivingEntity {
    public:
        /**
         * 构造函数
         * @param player 所属玩家方
         * @param config 战斗机配置项
         * @param parentEntity 父实体
         * @param x x坐标
         * @param y y坐标
         */
        Fighter(Player* const player, const FighterConfiguration& config,
         Entity* const parentEntity = (Entity*)0, const double x = 0, const double y = 0);
            
        /**
         * 析构函数
         */
        ~Fighter();
            
        /**
         * 死去
         */
        void die();
            
        /**
         * 获取视野内的实体
         */
        vector<Entity*> see() const;
            
        /**
         * 判断实体是否位于视野内
         * @param ano 实体
         */
        bool isInSight(const Entity& ano) const;
            
        /**
         * 射击
         * @param direction 方向，以y轴正半轴为0，逆时针为正，弧度制
         */
        bool shoot(const double direction) const;
            
        /**
         * 是否处于采集状态
         */
        bool isCollecting() const;
            
        /**
         * 采集资源实体
         * @param entity 资源实体
         */
        void collect(ResourceEntity& entity);

        /**
         * 采集实体完毕
         */  
        void collectCompletely();

        /**
         * 采集操作中止
         */
        void stopCollecting();

        /**
         * 开始采集的时间
         */
        long getStartTime() const;
    private:
        //正在采集的实体
        ResourceEntity* collectingEntity;
        //武器
        Weapon weapon;
        //战斗机配置项
        FighterConfiguration config;
        //是否处于采集状态
        bool collecting;
        //开始采集的时间
        long startTime;
};

#endif //_FIGHTER_H
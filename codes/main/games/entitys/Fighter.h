/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _FIGHTER_H
#define _FIGHTER_H

#include "LivingEntity.h"
#include "../../configs/FighterConfiguration.h"
#include "../conceptions/Weapon.h"
#include "../interfaces/Collector.h"
using std::enable_shared_from_this;

class Player;

class Fighter: public LivingEntity, public Collector {
    public:
        /**
         * 构造函数
         * @param player 所属玩家方
         * @param config 战斗机配置项
         * @param parentEntity 父实体
         * @param x x坐标
         * @param y y坐标
         */
        Fighter(shared_ptr<Player> const player, shared_ptr<FighterConfiguration> const config,
         shared_ptr<Entity> const parentEntity = nullptr, const double x = 0, const double y = 0);
            
        /**
         * 析构函数
         */
        ~Fighter();
            
        /**
         * 死去
         */
        virtual void die();
            
        /**
         * 获取视野内的实体
         */
        virtual vector<shared_ptr<Entity>> see() const;
            
        /**
         * 判断实体是否位于视野内
         * @param ano 实体
         */
        virtual bool isInSight(const Entity& ano) const;
            
        /**
         * 射击
         * @param direction 方向，以y轴正半轴为0，逆时针为正，弧度制
         */
        virtual bool shoot(const double direction) const;
            
        /**
         * 是否处于采集状态
         */
        virtual bool isCollecting() const;
            
        /**
         * 采集资源实体
         * @param entity 资源实体
         * @return 是否触发成功
         */
        virtual bool collect(shared_ptr<ResourceEntity> const entity);

        /**
         * 采集实体完毕
         */  
        virtual void collectCompletely();

        /**
         * 采集操作中止
         */
        virtual void stopCollecting();

        /**
         * 开始采集的时间
         */
        long getStartTime() const;

        /**
         * 重建需要的ticks
         */
        int getRebuildTicks() const;

        /**
         * 重建需要的资源
         */
        int getRebuildPower() const;

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

        /**
         * 采集是否完成
         * @return 是否完成
         */
        virtual bool collectFinished() const;
    private:
        //正在采集的实体
        shared_ptr<ResourceEntity> collectingEntity;
        //武器
        shared_ptr<Weapon> weapon;
        //是否处于采集状态
        bool collecting;
        //开始采集的时间
        long startTime;
        long endTime;
        //重造需要的ticks
        int rebuildTicks;
        //重造需要的资源
        int rebuildPower;
        shared_ptr<FighterConfiguration> config;
};

#endif //_FIGHTER_H

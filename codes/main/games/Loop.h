/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _LOOP_H
#define _LOOP_H

#include <set>
#include "../configs/LoopConfiguration.h"
#include "./entitys/ResourceEntity.h"
#include "./entitys/LivingEntity.h"
#include "./entitys/Bullet.h"
#include "Player.h"
#include <chrono>
using std::set, std::chrono::steady_clock, std::chrono::milliseconds;

class Engine;
class Logger;

class Loop {
    public: 
        /**
         * 构造函数
         * @param 配置项
         */
        Loop(LoopConfiguration* const config);

        /**
         * 析构函数
         */
        ~Loop();

        /**
         * 开始循环
         */
        void run();

        /**
         * 初始化
         */
        void init();
            
        /**
         * 玩家胜利结束游戏
         * @param winner 胜利的玩家
         */
        void endWithWinner(Player* const winner);

        /**
         * 时间用尽结束游戏
         */
        void endWithTimeOut();

        /**
         * 获取系统允许的最大tick
         * @param 最大tick值
         */
        long getMaxTickAllowed() const;

        /**
         * 添加资源实体
         * @param entity 资源实体
         */
        void addResourceEntity(ResourceEntity* const entity);

        /**
         * 添加子弹实体
         * @param entity 子弹
         */
        void addBullet(Bullet* const entity);

        /**
         * 添加生命实体
         * @param entity 生命实体
         */
        void addLivingEntity(LivingEntity* const entity);

        /**
         * 删除资源实体
         * @param entity 资源实体
         * @return 删除是否成功
         */
        bool removeResourceEntity(ResourceEntity* const entity);

        /**
         * 删除子弹实体
         * @param entity 子弹
         * @return 删除是否成功
         */
        bool removeBullet(Bullet* const entity);

        /**
         * 删除生命实体
         * @param entity 生命实体
         * @return 删除是否成功
         */
        bool removeLivingEntity(LivingEntity* const entity);

    private: 
        set<ResourceEntity*> allResourceEntity;
        set<Bullet*> allBullet;
        set<LivingEntity*> allLivingEntity;
        long nowTick;
        steady_clock::time_point nowTickStartTime;
        long maxTickAllowed;
        milliseconds timePerTick;
};

#endif //_LOOP_H

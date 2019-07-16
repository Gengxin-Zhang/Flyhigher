/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _LOOP_H
#define _LOOP_H

#include "../configs/LoopConfiguration.h"
#include "Player.h"
#include "./entitys/Bullet.h"
#include <chrono>
#include <set>
using std::set, std::chrono::steady_clock, std::chrono::milliseconds;

class Engine;
class Logger;

class Loop {
    public: 
        /**
         * 构造函数
         * @param 配置项
         */
        Loop(shared_ptr<LoopConfiguration> const config);

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
        void endWithWinner(shared_ptr<Player> const winner);

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
        void addResourceEntity(shared_ptr<ResourceEntity> const entity);

        /**
         * 添加子弹实体
         * @param entity 子弹
         */
        void addBullet(shared_ptr<Bullet> const entity);

        /**
         * 添加生命实体
         * @param entity 生命实体
         */
        void addLivingEntity(shared_ptr<LivingEntity> const entity);

        /**
         * 删除资源实体
         * @param entity 资源实体
         * @return 删除是否成功
         */
        bool removeResourceEntity(shared_ptr<ResourceEntity> const entity);

        /**
         * 删除子弹实体
         * @param entity 子弹
         * @return 删除是否成功
         */
        bool removeBullet(shared_ptr<Bullet> const entity);

        /**
         * 删除生命实体
         * @param entity 生命实体
         * @return 删除是否成功
         */
        bool removeLivingEntity(shared_ptr<LivingEntity> const entity);

    private: 
        set<shared_ptr<ResourceEntity>> allResourceEntity;
        set<shared_ptr<Bullet>> allBullet;
        set<shared_ptr<LivingEntity>> allLivingEntity;
        long nowTick;
        steady_clock::time_point nowTickStartTime;
        long maxTickAllowed;
        milliseconds timePerTick;
};

#endif //_LOOP_H

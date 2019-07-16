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
#include <map>
using std::chrono::steady_clock, std::chrono::milliseconds;

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
        bool removeResourceEntity(const int uid);

        /**
         * 删除子弹实体
         * @param entity 子弹
         * @return 删除是否成功
         */
        bool removeBullet(const int uid);

        /**
         * 删除生命实体
         * @param entity 生命实体
         * @return 删除是否成功
         */
        bool removeLivingEntity(const int uid);

        /**
         * 查找资源实体
         * @param uid 实体id
         * @return 实体指针，找不到返回null
         */
        shared_ptr<ResourceEntity> findResourceEntity(const int uid);

        /**
         * 查找子弹实体
         * @param uid 实体id
         * @return 实体指针，找不到返回null
         */
        shared_ptr<Bullet>  findBullet(const int uid);

        /**
         * 查找生命实体
         * @param uid 实体id
         * @return 实体指针，找不到返回null
         */
        shared_ptr<LivingEntity> findLivingEntity(const int uid);

        /**
         * 查找实体
         * @param uid 实体id
         * @return 实体指针，找不到返回null
         */
        shared_ptr<Entity> findEntity(const int uid);

        /**
         * 获取当前tick
         * @return 当前的tick
         */
        long getNowTick() const;

    private:
        std::map<int,shared_ptr<Entity>> allEntity;
        std::map<int,shared_ptr<ResourceEntity>> allResourceEntity;
        std::map<int,shared_ptr<Bullet>> allBullet;
        std::map<int,shared_ptr<LivingEntity>> allLivingEntity;
        long nowTick;
        steady_clock::time_point nowTickStartTime;
        long maxTickAllowed;
        milliseconds timePerTick;
};

#endif //_LOOP_H

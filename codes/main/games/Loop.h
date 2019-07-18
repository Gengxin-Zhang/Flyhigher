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
#include <set>
#include <utility>
using std::chrono::steady_clock, std::chrono::milliseconds;
using std::pair, std::set;

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

        /**
         * 是否有玩家获胜
         * @return 是否
         */
        bool hasPlayerWin();

    private:
        /**
         * 为一个活实体进行的边界检测
         * @param p 活实体map对
         */
        static void edgeCheckForALivingEntity(pair<int, shared_ptr<LivingEntity>> p);

        /**
         * 对活实体进行边界检测
         */
        void edgeCheckForLivingEntity();

        /**
         * 对子弹进行边界检测
         */
        void edgeCheckForBullet();

        /**
         * 对活实体和活实体进行碰撞检测
         */
        void impactCheckForLivingEntityAndLivingEntity();

        /**
         * 对子弹和子弹进行碰撞检测
         */
        void impactCheckForBulletAndBullet();

        /**
         * 对子弹和活实体进行碰撞检测
         */
        void impactCheckForBulletAndLivingEntity();

        /**
         * 让每个可移动实体延其运动向量走一个tick的距离
         */
        void moveNextTick();

        /**
         * 以文本信息的形式显示当前tick的各实体动态
         * 请注意，本函数只在debug模式下有效
         */
        void showInText() const;

        /**
         * 母舰恢复检测
         */
        void healCheck();

        /**
         * 建造完毕检测
         */
        void buildFinishedCheck();

        /**
         * 采集完毕检测
         */
        void collectFinishedCheck();

        /**
         * 视野检测
         */
        map<shared_ptr<LivingEntity>, set<shared_ptr<Entity>>> sightsOperate();

        /**
         * 使用超级武器造成爆炸
         * @param nuke 子弹
         */
        void nuke_boom(shared_ptr<Bullet> const nuke);
        std::map<int,shared_ptr<Entity>> allEntity;
        std::map<int,shared_ptr<ResourceEntity>> allResourceEntity;
        std::map<int,shared_ptr<Bullet>> allBullet;
        std::map<int,shared_ptr<LivingEntity>> allLivingEntity;
        long nowTick;
        steady_clock::time_point nowTickStartTime;
        steady_clock::time_point nowTickEndTime;
        long maxTickAllowed;
        milliseconds timePerTick;
};

#endif //_LOOP_H

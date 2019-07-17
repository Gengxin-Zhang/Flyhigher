/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _LIVINGENTITY_H
#define _LIVINGENTITY_H

#include "MovableEntity.h"
#include "../../configs/PlaneConfiguration.h"
using std::vector, std::enable_shared_from_this;

class Player;

class LivingEntity: public MovableEntity, public enable_shared_from_this<LivingEntity>{
    public: 
        /**
         * 构造函数
         * @param player 所属玩家方
         * @param config 飞机实体配置项
         * @param parentEntity 父实体
         * @param x x坐标
         * @param y y坐标
         */
        LivingEntity(shared_ptr<Player> const player, shared_ptr<PlaneConfiguration> const config,
        shared_ptr<Entity> const parentEntity = nullptr, const double x = 0, const double y = 0);

        /**
         * 获取最大生命值
         * @return 最大生命值
         */
        int getMaxHealth() const;

        /**
         * 获取当前生命值
         * @return 当前生命值
         */
        int getNowHealth() const;
            
        /**
         * 治疗一定生命值，原则上是正数
         * @param health 回复
         */
        void heal(const int health);
            
        /**
         * 受到一定伤害，原则上是正数
         * @param damage 伤害
         * @return 是否死亡
         */
        bool damage(const int damage);
            
        /**
         * 出生
         */
        virtual void init();
            
        /**
         * 消亡
         */
        virtual void die();
        
        /**
         * 获取所属玩家方
         * @return 玩家
         */
        shared_ptr<Player> getPlayer() const;

        /**
         * 获取治疗速率
         * @return 治疗速率
         */
        int getHealRate() const;

        /**
         * 获取治疗消耗的资源
         * @return 资源
         */
        int getHealPower() const;
            
        /**
         * 析构函数
         */
        virtual ~LivingEntity();
            
        /**
         * 判断实体是否在视野内
         * @param ano 实体
         */
        virtual bool isInSight(const Entity& ano) const = 0;
            
        /**
         * 射击
         * @param direction 射击方向
         * @return 是否成功触发射击，若处于CD等情况会触发失败
         */
        virtual bool shoot(const double direction) const = 0;

        /**
         * 距离下一次射击还有多久冷却时间
         * @return 冷却时间
         */
        virtual int getWeaponCD() const = 0;

        /**
         * 将实体以字符串显示
         * @return 字符串
         */
        virtual string toString() const;

        /**
         * 获取类型名称
         * @return 类型名称
         */
        virtual string getClassName() const;

        /**
         * 实体是否已死
         * @return 是否处于死亡状态
         */
        bool isDeath() const;
    private: 
        //当前状态的生命值
        int nowHealth;
        //最大生命值
        int maxHealth;
        //治疗速率
        int healRate;
        //治疗消耗的资源
        int healPower;
        //所属玩家方
        shared_ptr<Player> player;
        bool death;
};

#endif //_LIVINGENTITY_H

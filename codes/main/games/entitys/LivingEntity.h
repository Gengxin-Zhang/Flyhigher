/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _LIVINGENTITY_H
#define _LIVINGENTITY_H

#include "MovableEntity.h"
#include "../conceptions/Player.h"
#include <vector>
using std::vector;


class LivingEntity: public MovableEntity {
    public: 
        /**
         * 构造函数
         * @param player 所属玩家方
         * @param radius 碰撞半径
         * @param maxHealth 最大生命值
         * @param parentEntity 父实体
         * @param x x坐标
         * @param y y坐标
         */
        LivingEntity(Player* const player, const double radius, const int maxHealth, const Vector2D speed = Vector2D(),
        Entity* const parentEntity = (Entity*)0, const double x = 0, const double y = 0);

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
         */
        void damage(const int damage);
            
        /**
         * 出生
         */
        virtual void init();
            
        /**
         * 消亡
         */
        virtual void die();
            
        /**
         * 析构函数
         */
        ~LivingEntity();
            
        /**
         * 视野内的所有实体
         */
        virtual vector<Entity*> see() = 0;
            
        /**
         * 判断实体是否在视野内
         * @param ano 实体
         */
        virtual bool isInSight(const Entity& ano) = 0;
            
        /**
         * 射击
         * @param direction 射击方向
         * @return 是否成功触发射击，若处于CD等情况会触发失败
         */
        virtual bool shoot(const double direction) = 0;
    private: 
        //当前状态的生命值
        int nowHealth;
        //最大生命值
        int maxHealth;
        //所属玩家方
        Player* player;
};

#endif //_LIVINGENTITY_H
/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _MOVABLEENTITY_H
#define _MOVABLEENTITY_H

#include "Entity.h"


class MovableEntity: public Entity {
    public: 
        /**
         * 构造函数
         * @param radius 碰撞半径
         * @param speed 速度向量
         * @param parentEntity 父实体
         * @param x x坐标
         * @param y y坐标
         */
        MovableEntity(const double radius, const Vector2D speed = Vector2D(),
         Entity* const parentEntity = (Entity*)0, const double x = 0, const double y = 0);
            
        /**
         * 获取速度向量
         */
        Vector2D getSpeed() const;
            
        /**
         * 改变速度向量的方向，弧度制，每次改变不能超过绝对值pai/24
         * @param rad
         */
        void turnDirection(const double rad);
            
        /**
         * 向当前速度向量的位置移动，时间是1tick。
         */
        void goNextTick();
            
        /**
         * 析构函数
         */
        ~MovableEntity();
    private: 
        //速度向量
        Vector2D speed;
};

#endif //_MOVABLEENTITY_H
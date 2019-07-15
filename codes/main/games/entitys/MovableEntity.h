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
         Entity* const parentEntity = nullptr, const double x = 0, const double y = 0);
            
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
         * 是否处于移动状态，false表示静止
         * @return 移动状态
         */
        bool isMoving() const;

        /**
         * 设置移动状态，false表示静止
         * @param moving 移动状态
         */
        void setMoving(const bool moving);

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
         * 析构函数
         */
        ~MovableEntity();
    private: 
        //速度向量
        Vector2D speed;
        //是否移动
        bool moving;
};

#endif //_MOVABLEENTITY_H

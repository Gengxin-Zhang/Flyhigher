/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _BULLET_H
#define _BULLET_H

#include "LivingEntity.h"
#include "../interfaces/Damageable.h"


class Bullet: public MovableEntity, public Damageable {
    public:
        /**
         * 构造函数
         * @param radius 碰撞半径
         * @param speed 速度向量
         * @param damage 造成的伤害值
         * @param parentEntity 父实体
         * @param x x坐标
         * @param y y坐标
         */
        Bullet(const double radius, const Vector2D speed, const int damage,
         shared_ptr<Entity> const parentEntity = nullptr, const double x = 0, const double y = 0);
            
        /**
         * 获取击中实体造成的伤害值
         */
        int getDamage() const;
            
        /**
         * 对一个实体造成伤害
         * @param entity 实体
         */
        virtual bool damageTo(LivingEntity& entity) const;

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
        ~Bullet();
    private:
        //子弹击中造成的伤害
        int damage;
};

#endif //_BULLET_H

/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _NUKE_H
#define _NUKE_H

class Nuke {
    public:
        /**
         * 是否已经发射
         * @return 是否已经发射过
         */
        bool hasShoot() const;
        
        /**
         * 获取AOE伤害值
         * @return 伤害值
         */
        int getAoeDamage() const;
        
        /**
         * 获取AOE伤害半径
         * @return AOE伤害半径
         */
        double getAoeDamageRadius() const;
        
        /**
         * 获取伤害衰减，单位px
         * @return 每px的衰减值
         */
        int getDamageDecrease() const;
        
        /**
         * 获取子弹碰撞半径
         * @return 碰撞半径
         */
        double getRadius() const;
        
        /**
         * 获取子弹速度标量
         * #return 速度标量
         */
        int getSpeed() const;
        
        /**
         * 向固定方位开火，弧度制，与y轴正半轴的夹角，逆时针为正
         * @param direction 方位角
         * @return 是否成功开火
         */
        bool shoot(const double direction) const;
            
        /**
         * 构造函数
         * @param aoeDamage AOE伤害
         * @param aoeDamageRadius AOE伤害半径
         * @param damageDecrease 伤害衰减，单位px
         * @param radius 子弹碰撞半径
         * @param speed 子弹速度标量
         */
        Nuke(const int aoeDamage, const double aoeDamageRadius, const int damageDecrease, const double radius, const int speed);

        /**
         * 析构函数
         */
        ~Nuke();
    private: 
        bool shooted;
        int aoeDamage;
        double aoeDamageRadius;
        int damageDecrease;
        double radius;
        int speed;
};

#endif //_NUKE_H
/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _NUKECONFIGURATION_H
#define _NUKECONFIGURATION_H

class NukeConfiguration {
    public: 
        /**
         * 获取AOE中心伤害
         * @return 伤害值
         */
        int getAoeDamage() const;
        
        /**
         * 获取AOE伤害半径
         * @return 伤害半径
         */
        double getAoeDamageRadius() const;
        
        /**
         * 获取伤害缩减值，单位每tick
         * @return 伤害缩减
         */
        int getDamageDecrease() const;
        
        /**
         * 获取子弹碰撞半径
         * @return 碰撞半径
         */
        double getRadius() const;
        
        /**
         * 获取子弹速度标量
         * @return 速度
         */
        int getSpeed() const;
            
        /**
         * 构造函数
         * @param aoeDamage
         * @param aoeDamageRadius
         * @param damageDecrease
         * @param radius
         * @param speed
         */
        NukeConfiguration(const int aoeDamage, const double aoeDamageRadius, const int damageDecrease, const double radius, const int speed);
        
        /**
         * 析构函数
         */
        ~NukeConfiguration();
    private: 
        int aoeDamage;
        double aoeDamageRadius;
        int damageDecrease;
        double radius;
        int speed;
};

#endif //_NUKECONFIGURATION_H
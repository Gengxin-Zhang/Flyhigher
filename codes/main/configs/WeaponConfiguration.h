/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _WEAPONCONFIGURATION_H
#define _WEAPONCONFIGURATION_H

class WeaponConfiguration {
    public:
        /**
         * 返回武器子弹的碰撞半径
         * @return 碰撞半径
         */
        double getRadius() const;

        /**
         * 返回武器子弹的伤害
         * @return 伤害
         */
        int getDamage() const;

        /**
         * 返回武器子弹的速度标量
         * @return 速度
         */
        int getSpeed() const;

        /**
         * 返回武器射击的冷却时间，单位tick
         * @return 冷却时间
         */
        int getDelay() const;
    
        /**
         * 构造函数
         * @param radius 子弹碰撞半径
         * @param damage 子弹伤害
         * @param speed 子弹速度
         * @param delay 射击冷却时间
         */
        WeaponConfiguration(const double radius, const int damage, const int speed, const int delay);
        
        /**
         * 析构函数
         */
        ~WeaponConfiguration();
    private: 
        double radius;
        int damage;
        int speed;
        int delay;
};

#endif //_WEAPONCONFIGURATION_H

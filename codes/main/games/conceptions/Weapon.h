/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _WEAPON_H
#define _WEAPON_H

class Weapon {
    public: 
        /**
         * 构造函数
         * @param radius 子弹碰撞半径
         * @param damage 子弹伤害
         * @param speed 子弹速度
         * @param delay 子弹冷却时间，单位tick
         */
        Weapon(const double radius, const double damage, const int speed, const int delay);
        
        /**
         * 析构函数
         */
        ~Weapon();
            
        /**
         * 发射子弹，参数为方向，相对于y轴正半轴，逆时针为正的弧度角
         * @param direction 方向弧度角
         * @return 是否成功发射
         */
        bool shoot(const double direction) const;
        
        /**
         * 获取子弹碰撞半径
         * @return 碰撞半径
         */
        double getRadius() const;
        
        /**
         * 获取子弹伤害
         * @return 子弹伤害
         */
        double getDamage() const;
        
        /**
         * 获取子弹速度标量
         * @return 子弹速度
         */
        int getSpeed() const;
        
        /**
         * 获取射击冷却时间，单位tick
         * @return 冷却时间
         */
        int getDelay() const;
        
        /**
         * 获取上一次发射子弹的时候的tick
         * @return 上次发射子弹的时间
         */
        long getLastShoot() const;
    private: 
        double radius;
        double damage;
        int speed;
        int delay;
        long lastShoot;
};

#endif //_WEAPON_H
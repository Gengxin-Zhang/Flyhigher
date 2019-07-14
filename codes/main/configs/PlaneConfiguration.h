/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _PLANECONFIGURATION_H
#define _PLANECONFIGURATION_H

class PlaneConfiguration {
    public: 
        /**
         * 返回最大生命值
         * @return 最大生命值
         */
        int getMaxHealth() const;

        /**
         * 返回在母舰的治疗速率，单位tick的治疗量
         * @return 治疗量
         */
        int getHealRate() const;

        /**
         * 返回在母舰治疗一次消耗的资源点数
         * @return 资源点数
         */
        int getHealPower() const;

        /**
         * 返回移动速度的标量
         * @return 战斗机的移动速度
         */
        double getSpeed() const;

        /**
         * 返回飞机的碰撞半径
         * @return 碰撞半径
         */
        double getRadius() const;
    
        /**
         * 构造函数
         * @param maxHealth 最大生命值
         * @param speed 速度
         * @param radius 碰撞半径
         * @param healRate 治疗速度
         * @param healPower 治疗消耗资源
         */
        PlaneConfiguration(const int maxHealth, const double speed, const double radius, const int healRate, const int healPower);
        
        /**
         * 析构函数
         */
        ~PlaneConfiguration();
    private: 
        int maxHealth;
        double speed;
        double radius;
        int healRate;
        int healPower;
};

#endif //_PLANECONFIGURATION_H

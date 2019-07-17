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
         * 获取视角，运动方向的正负偏角
         * @return 视角，正数，弧度制
         */
        double getSightAngle() const;

        /**
         * 获取长视野半径，运动时候的扇形视野半径
         * @return 半径
         */
        double getLongSight() const;

        /**
         * 获取短视野半径，静止时的圆形视野半径
         * @return 半径
         */
        double getShortSight() const;

        /**
         * 构造函数
         * @param maxHealth 最大生命值
         * @param speed 速度
         * @param radius 碰撞半径
         * @param healRate 治疗速度
         * @param healPower 治疗消耗资源
         * @param sightAngle 视角
         * @param sightAngle 长视野
         * @param sightAngle 短视野
         */
        PlaneConfiguration(const int maxHealth, const double speed, const double radius, const int healRate,
                           const int healPower, const double sightAngle, const double longSight, const double shortSight);
        
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
        double sightAngle;
        double longSight;
        double shortSight;
};

#endif //_PLANECONFIGURATION_H

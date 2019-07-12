/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _FIGHTERCONFIGURATION_H
#define _FIGHTERCONFIGURATION_H

class FighterConfiguration {
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
        int getSpeed() const;

        /**
         * 返回武器子弹的碰撞半径
         * @return 碰撞半径
         */
        double getBulletRadius() const;

        /**
         * 返回武器子弹的伤害
         * @return 伤害
         */
        int getBulletDamage() const;

        /**
         * 返回武器子弹的速度标量
         * @return 速度
         */
        int getBulletSpeed() const;

        /**
         * 返回武器射击的冷却时间，单位tick
         * @return 冷却时间
         */
        int getShootDelay() const;

        /**
         * 返回重新建造一个战斗机需要的资源
         * @return 资源需求
         */
        int getRebuildPower() const;
            
        /**
         * 返回重新建造一个战斗机需要的时间，单位tick
         * @return 需要的时间
         */
        int getRebuildTick() const;

        /**
         * 返回战斗机的碰撞半径
         */
        double getFighterRadius() const;
            
        /**
         * 构造函数
         * @param maxHealth 最大生命值
         * @param healRate 恢复速度
         * @param healPower 恢复所需能量
         * @param speed 速度标量
         * @param bulletRadius 子弹碰撞半径
         * @param bulletDamage 子弹伤害
         * @param bulletSpeed 子弹速度标量
         * @param shootDelay 射击冷却时间
         * @param rebuildPower 重建需要资源
         * @param rebuildTick 重建所需时间
         * @param fighterRadius 战斗机碰撞半径
         */
        FighterConfiguration(const int maxHealth, const int healRate, const int healPower, const int speed,
        const double bulletRadius, const int bulletDamage, const int bulletSpeed, const int shootDelay, const int rebuildPower,
        const int rebuildTick, const double fighterRadius);

        /**
         * 析构函数
         */
        ~FighterConfiguration();
    private: 
        int maxHealth;
        int healRate;
        int healPower;
        int speed;
        double bulletRadius;
        int bulletDamage;
        int bulletSpeed;
        int shootDelay;
        int rebuildPower;
        int rebuildTick;
        double fighterRadius;
};

#endif //_FIGHTERCONFIGURATION_H
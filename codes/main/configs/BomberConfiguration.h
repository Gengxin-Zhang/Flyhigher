/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _BOMBERCONFIGURATION_H
#define _BOMBERCONFIGURATION_H

class BomberConfiguration {
public: 
    
int getMaxHealth();
    
int getHealRate();
    
int getHealPower();
    
int getSpeed();
    
double getBulletRadius();
    
int getBulletDamage();
    
int getBulletSpeed();
    
int getBulletDelay();
    
double getBomberRadius();
    
/**
 * @param maxHealth
 * @param healRate
 * @param healPower
 * @param speed
 * @param bulletRadius
 * @param bulletDamage
 * @param bulletSpeed
 * @param bulletDelay
 * @param bomberRadius
 */
BomberConfiguration(int maxHealth, int healRate, int healPower, int speed, double bulletRadius, int bulletDamage, int bulletSpeed, int bulletDelay, double bomberRadius);
    
~BomberConfiguration();
private: 
    int maxHealth;
    int healRate;
    int healPower;
    int speed;
    double bulletRadius;
    int bulletDamage;
    int bulletSpeed;
    int bulletDelay;
    double bomberRadius;
};

#endif //_BOMBERCONFIGURATION_H
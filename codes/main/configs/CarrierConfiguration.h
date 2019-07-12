/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _CARRIERCONFIGURATION_H
#define _CARRIERCONFIGURATION_H

class CarrierConfiguration {
public: 
    
int getMaxHealth();
    
int getSpeed();
    
double getBulletRadius();
    
int getBulletDamage();
    
int getBulletSpeed();
    
int getBulletDelay();
    
int getNukeAOEDamage();
    
double getNukeAOEDamageRadius();
    
int getNukeDamageDecrease();
    
int getNukeCenterDamage();
    
double getNukeRadius();
    
int getNukeSpeed();
    
double getCarrierRadius();
    
/**
 * @param maxHealth
 * @param speed
 * @param bulletRadius
 * @param bulletDamage
 * @param bullletSpeed
 * @param bulletDelay
 * @param nukeAOEDamage
 * @param nukeAOEDamageRadius
 * @param nukeDamageDecrease
 * @param nukeCenterDamage
 * @param nukeRadius
 * @param nukeSpeed
 * @param carrierRadius
 */
CarrierConfiguration(int maxHealth, int speed, double bulletRadius, int bulletDamage, int bullletSpeed, int bulletDelay, int nukeAOEDamage, double nukeAOEDamageRadius, int nukeDamageDecrease, inr nukeCenterDamage, double nukeRadius, int nukeSpeed, double carrierRadius);
    
~CarrierConfiguration();
private: 
    int maxHealth;
    int speed;
    double bulletRadius;
    int bulletDamage;
    int bulletSpeed;
    int bulletDelay;
    int nukeAOEDamage;
    double nukeAOEDamageRadius;
    int nukeDamageDecrease;
    int nukeCenterDamage;
    double nukeRadius;
    int nukeSpeed;
    double carrierRadius;
};

#endif //_CARRIERCONFIGURATION_H
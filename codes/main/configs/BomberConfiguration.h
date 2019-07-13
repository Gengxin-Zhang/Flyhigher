/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _BOMBERCONFIGURATION_H
#define _BOMBERCONFIGURATION_H

class BomberConfiguration {
public: 
    
/**
 * @param weaponConfig
 * @param config
 */
void BomberConfiguration(WeaponConfiguration weaponConfig, PlaneConfiguration config);
    
void ~BomberConfiguration();
    
WeaponConfiguration getWeaponConfig();
    
PlaneConfiguration getConfig();
private: 
    WeaponConfiguration weaponConfig;
    PlaneConfiguration config;
};

#endif //_BOMBERCONFIGURATION_H
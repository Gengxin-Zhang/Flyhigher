/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _CARRIERCONFIGURATION_H
#define _CARRIERCONFIGURATION_H

class CarrierConfiguration {
public: 
    NukeConfiguration nukeConfig;
    PlaneConfiguration config;
    
/**
 * @param weaponConfig
 * @param nukeConfig
 * @param config
 */
void CarrierConfiguration(WeaponConfiguration weaponConfig, NukeConfiguration nukeConfig, PlaneConfiguration config);
    
void ~CarrierConfiguration();
    
WeaponConfiguration getWeaponConfig();
    
NukeConfiguration getNukeConfig();
    
PlaneConfiguration getConfig();
private: 
    WeaponConfiguration weaponConfig;
};

#endif //_CARRIERCONFIGURATION_H
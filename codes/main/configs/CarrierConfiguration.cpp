/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "CarrierConfiguration.h"

/**
 * CarrierConfiguration implementation
 */

CarrierConfiguration::CarrierConfiguration(WeaponConfiguration* const weaponConfig,
 NukeConfiguration* const nukeConfig, PlaneConfiguration* const config) {
     this->weaponConfig = weaponConfig;
     this->nukeConfig = nukeConfig;
     this->config = config;
}

CarrierConfiguration::~CarrierConfiguration() {
    delete [] weaponConfig;
    delete [] nukeConfig;
    delete [] config;
}

WeaponConfiguration* CarrierConfiguration::getWeaponConfig() const{
    return weaponConfig;
}

NukeConfiguration* CarrierConfiguration::getNukeConfig() const{
    return nukeConfig;
}

PlaneConfiguration* CarrierConfiguration::getConfig() const{
    return config;
}
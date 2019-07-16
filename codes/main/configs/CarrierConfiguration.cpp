/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "CarrierConfiguration.h"

/**
 * CarrierConfiguration implementation
 */

CarrierConfiguration::CarrierConfiguration(shared_ptr<WeaponConfiguration> const weaponConfig,
                                           shared_ptr<NukeConfiguration> const nukeConfig,
                                           shared_ptr<PlaneConfiguration> const config) {
     this->weaponConfig = weaponConfig;
     this->nukeConfig = nukeConfig;
     this->config = config;
}

CarrierConfiguration::~CarrierConfiguration() {
}

shared_ptr<WeaponConfiguration> CarrierConfiguration::getWeaponConfig() const{
    return weaponConfig;
}

shared_ptr<NukeConfiguration> CarrierConfiguration::getNukeConfig() const{
    return nukeConfig;
}

shared_ptr<PlaneConfiguration> CarrierConfiguration::getConfig() const{
    return config;
}

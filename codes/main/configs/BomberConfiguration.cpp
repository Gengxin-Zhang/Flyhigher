/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "BomberConfiguration.h"

/**
 * BomberConfiguration implementation
 */

BomberConfiguration::BomberConfiguration(shared_ptr<WeaponConfiguration> const weaponConfig,
                                         shared_ptr<PlaneConfiguration> const config) {
    this->weaponConfig = weaponConfig;
    this->config = config;
}

BomberConfiguration::~BomberConfiguration() {
}

shared_ptr<WeaponConfiguration> BomberConfiguration::getWeaponConfig() const{
    return weaponConfig;
}

shared_ptr<PlaneConfiguration> BomberConfiguration::getConfig() const{
    return config;
}

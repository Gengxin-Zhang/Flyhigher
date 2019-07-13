/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "BomberConfiguration.h"

/**
 * BomberConfiguration implementation
 */

BomberConfiguration::BomberConfiguration(WeaponConfiguration* const weaponConfig, PlaneConfiguration* const config) {
    this->weaponConfig = weaponConfig;
    this->config = config;
}

BomberConfiguration::~BomberConfiguration() {
    delete [] weaponConfig;
    delete [] config;
}

WeaponConfiguration* BomberConfiguration::getWeaponConfig() const{
    return weaponConfig;
}

PlaneConfiguration* BomberConfiguration::getConfig() const{
    return config;
}
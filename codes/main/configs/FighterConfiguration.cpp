/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "FighterConfiguration.h"

/**
 * FighterConfiguration implementation
 */

FighterConfiguration::FighterConfiguration(WeaponConfiguration* const weaponConfig,
 RebuildableConfiguration* const rebuildConfig, PlaneConfiguration* const config) {
    this->weaponConfig = weaponConfig;
    this->rebuildConfig = rebuildConfig;
    this->config = config;
}

FighterConfiguration::~FighterConfiguration() {
    delete [] weaponConfig;
    delete [] rebuildConfig;
    delete [] config;
}

WeaponConfiguration* FighterConfiguration::getWeaponConfig() const{
    return weaponConfig;
}

RebuildableConfiguration* FighterConfiguration::getRebuildConfig() const{
    return rebuildConfig;
}

PlaneConfiguration* FighterConfiguration::getConfig() const{
    return config;
}
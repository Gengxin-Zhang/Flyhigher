/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "FighterConfiguration.h"

/**
 * FighterConfiguration implementation
 */

FighterConfiguration::FighterConfiguration(shared_ptr<WeaponConfiguration> const weaponConfig,
                                           shared_ptr<RebuildableConfiguration> const rebuildConfig,
                                           shared_ptr<PlaneConfiguration> const config) {
    this->weaponConfig = weaponConfig;
    this->rebuildConfig = rebuildConfig;
    this->config = config;
}

FighterConfiguration::~FighterConfiguration() {
}

shared_ptr<WeaponConfiguration> FighterConfiguration::getWeaponConfig() const{
    return weaponConfig;
}

shared_ptr<RebuildableConfiguration> FighterConfiguration::getRebuildConfig() const{
    return rebuildConfig;
}

shared_ptr<PlaneConfiguration> FighterConfiguration::getConfig() const{
    return config;
}

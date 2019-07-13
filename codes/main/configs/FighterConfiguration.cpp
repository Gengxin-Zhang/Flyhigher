/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "FighterConfiguration.h"

/**
 * FighterConfiguration implementation
 */

FighterConfiguration::FighterConfiguration(const WeaponConfiguration& weaponConfig,
 const RebuildableConfiguration& rebuildConfig, const PlaneConfiguration& config) {
    this->weaponConfig = weaponConfig;
    this->rebuildConfig = rebuildConfig;
    this->config = config;
}

FighterConfiguration::~FighterConfiguration() {

}

const WeaponConfiguration& FighterConfiguration::getWeaponConfig() const{
    return weaponConfig;
}

const RebuildableConfiguration& FighterConfiguration::getRebuildConfig() const{
    return rebuildConfig;
}

const PlaneConfiguration& FighterConfiguration::getConfig() const{
    return config;
}
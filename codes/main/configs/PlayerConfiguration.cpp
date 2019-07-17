/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "PlayerConfiguration.h"

/**
 * PlayerConfiguration implementation
 */


PlayerConfiguration::PlayerConfiguration(shared_ptr<CarrierConfiguration> const carrierConfig,
                                         shared_ptr<BomberConfiguration> const bomberConfig,
                                         shared_ptr<FighterConfiguration> const fighterConfig) {
    this->carrierConfig = carrierConfig;
    this->bomberConfig = bomberConfig;
    this->fighterConfig =fighterConfig;
}

PlayerConfiguration::~PlayerConfiguration() {
}

shared_ptr<CarrierConfiguration> PlayerConfiguration::getCarrierConfig() const{
    return carrierConfig;
}

shared_ptr<BomberConfiguration> PlayerConfiguration::getBomberConfig() const{
    return  bomberConfig;
}

shared_ptr<FighterConfiguration> PlayerConfiguration::getFighterConfig() const{
    return fighterConfig;
}

/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "PlayerConfiguration.h"

/**
 * PlayerConfiguration implementation
 */


PlayerConfiguration::PlayerConfiguration(const string name, const Color color,
     CarrierConfiguration* const carrierConfig, BomberConfiguration* const bomberConfig,
     FighterConfiguration* const fighterConfig) {
    this->name = name;
    this->color = color;
    this->carrierConfig = carrierConfig;
    this->bomberConfig = bomberConfig;
    this->fighterConfig =fighterConfig;
}

PlayerConfiguration::~PlayerConfiguration() {
    delete [] carrierConfig;
    delete [] bomberConfig;
    delete [] fighterConfig;
}

string PlayerConfiguration::getName() const{
    return name;
}

Color PlayerConfiguration::getColor() const{
    return color;
}

CarrierConfiguration* PlayerConfiguration::getCarrierConfig() const{
    return carrierConfig;
}

BomberConfiguration* PlayerConfiguration::getBomberConfig() const{
    return  bomberConfig;
}

FighterConfiguration* PlayerConfiguration::getFighterConfig() const{
    return fighterConfig;
}

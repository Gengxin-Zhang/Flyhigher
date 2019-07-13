/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "PlayerConfiguration.h"

/**
 * PlayerConfiguration implementation
 */


PlayerConfiguration::PlayerConfiguration(const string name, const Color color) {
    this->name = name;
    this->color = color;
}

PlayerConfiguration::~PlayerConfiguration() {

}

string PlayerConfiguration::getName() const{
    return name;
}

Color PlayerConfiguration::getColor() const{
    return color;
}
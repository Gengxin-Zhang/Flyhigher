/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */

#include "LittleStarConfiguration.h"

/**
 * LittleStarConfiguration implementation
 */


LittleStarConfiguration::LittleStarConfiguration(const int power, const double radius){
    this->power = power;
    this->radius = radius;
}

LittleStarConfiguration::~LittleStarConfiguration(){

}


int LittleStarConfiguration::getPower() const{
    return power;
}

double LittleStarConfiguration::getRadius() const{
    return radius;
}

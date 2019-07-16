/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */

#include "LittleStarConfiguration.h"

/**
 * LittleStarConfiguration implementation
 */


LittleStarConfiguration::LittleStarConfiguration(const int power, const double radius, const int collectTick){
    this->power = power;
    this->radius = radius;
    this->collectTick = collectTick;
}

LittleStarConfiguration::~LittleStarConfiguration(){

}


int LittleStarConfiguration::getPower() const{
    return power;
}

double LittleStarConfiguration::getRadius() const{
    return radius;
}

int LittleStarConfiguration::getCollectTick() const{
    return collectTick;
}

/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */

#include "LargeStarConfiguration.h"

/**
 * LargeStarConfiguration implementation
 */
LargeStarConfiguration::LargeStarConfiguration(const int power, const double radius){
    this->power = power;
    this->radius =radius;
}

LargeStarConfiguration::~LargeStarConfiguration(){

}

int LargeStarConfiguration::getPower() const{
    return power;
}

double LargeStarConfiguration::getRadius() const{
    return radius;
}


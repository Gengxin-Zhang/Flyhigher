/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "RebuildableConfiguration.h"

/**
 * RebuildableConfiguration implementation
 */

int RebuildableConfiguration::getPower() const{
    return power;
}
            
int RebuildableConfiguration::getTick() const{
    return ticks;
}

RebuildableConfiguration::RebuildableConfiguration(int power, int ticks) {
    this->power = power;
    this->ticks = ticks;
}

RebuildableConfiguration::~RebuildableConfiguration() {

}
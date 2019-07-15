/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "LoopConfiguration.h"

/**
 * LoopConfiguration implementation
 */

long LoopConfiguration::getMaxTickAllowed() const{
    return maxTickAllowed;
}

milliseconds LoopConfiguration::getTimePerTick() const{
    return timePerTick;
}

LoopConfiguration::LoopConfiguration(const long maxTickAllowed, const milliseconds timePerTick) {
    this->maxTickAllowed = maxTickAllowed;
    this->timePerTick = timePerTick;
}

LoopConfiguration::~LoopConfiguration() {

}

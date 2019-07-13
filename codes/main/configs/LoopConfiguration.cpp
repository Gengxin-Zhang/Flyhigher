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

LoopConfiguration::LoopConfiguration(const long maxTickAllowed) {
    this->maxTickAllowed = maxTickAllowed;
}

LoopConfiguration::~LoopConfiguration() {

}
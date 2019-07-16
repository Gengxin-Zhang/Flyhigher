/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "JudgerConfiguration.h"

/**
 * JudgerConfiguration implementation
 */

JudgerConfiguration::JudgerConfiguration(const int maxTimeout){
    this->maxTimeout = maxTimeout;
}

JudgerConfiguration::~JudgerConfiguration(){

}

int JudgerConfiguration::getMaxTimeout() const{
    return maxTimeout;
}

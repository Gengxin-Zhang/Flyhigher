/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Configuration.h"

/**
 * Configuration implementation
 */

bool Configuration::isInit = false;

shared_ptr<Configuration> Configuration::config = nullptr;

Configuration::Configuration(const string file) {
    this->file = file;
    root = YAML::Load(file);
}

Configuration::~Configuration() {
}

shared_ptr<Configuration> Configuration::getInstance() {
    if(!isInit){
        config = shared_ptr<Configuration>(new Configuration("./config.yml"));
        isInit = true;
    }
    return config;
}

void Configuration::reload() {
    root = YAML::Load(file);
}

void Configuration::load() {

}

shared_ptr<GameConfiguration> Configuration::getGameConfiguration() const{
    return gameConfig;
}

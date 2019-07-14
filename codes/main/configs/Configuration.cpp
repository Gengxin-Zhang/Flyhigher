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

Configuration* Configuration::config = (Configuration*) 0;

Configuration::Configuration(const string file) {
    this->file = file;
    root = YAML::Load(file);
}

Configuration::~Configuration() {
    delete [] gameConfig;
}

Configuration* Configuration::getInstance() {
    if(!isInit){
        config = new Configuration("./config.yml");
        isInit = true;
    }
    return config;
}

void Configuration::reload() {
    root = YAML::Load(file);
}

void Configuration::load() {

}

GameConfiguration* Configuration::getGameConfiguration() const{
    return gameConfig;
}

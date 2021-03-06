/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H

#include <string>
#include "yaml-cpp/yaml.h"
#include "GameConfiguration.h"
using std::string;

class Configuration {
    public:
        ~Configuration();

        void reload();

        shared_ptr<GameConfiguration> getGameConfiguration() const;

        static shared_ptr<Configuration> getInstance();

        void writeToYaml();

        YAML::Node getRoot() const;

        void setDefault();
    private:
        Configuration(const string file);
        static bool isInit;
        static shared_ptr<Configuration> config;
        shared_ptr<GameConfiguration> gameConfig;
        YAML::Node root;
        YAML::Emitter emitter;
        string file;
};

#endif //_CONFIGURATION_H

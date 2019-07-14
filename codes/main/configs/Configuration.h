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

class Engine;

class Configuration {
    public:
        ~Configuration();

        void reload();

        void load();

        GameConfiguration* getGameConfiguration() const;

        static Configuration* getInstance();
    private:
        Configuration(const string file);
        static bool isInit;
        static Configuration* config;
        GameConfiguration* gameConfig;
        YAML::Node root;
        string file;
};

#endif //_CONFIGURATION_H

/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "GameConfiguration.h"
#include <exception>
#include <string>
using std::invalid_argument, std::to_string;

/**
 * GameConfiguration implementation
 */

MapConfiguration* GameConfiguration::getMapConfig() const{
    return mapConfig;
}

JudgerConfiguration* GameConfiguration::getJudgerConfig() const{
    return judgerConfig;
}

LoopConfiguration* GameConfiguration::getLoopConfig() const{
    return loopConfig;
}

int GameConfiguration::getPlayerNumber() const{
    return playerNumber;
}

PlayerConfiguration* GameConfiguration::getPlayersConfig(const int index) const{
    if(index < 0 || index >= playerNumber){
        throw invalid_argument("index should not be " + to_string(index));
    }
    return playersConfig[index];
}

GameConfiguration::GameConfiguration(MapConfiguration* const mapConfig, JudgerConfiguration* const judgerConfig,
 LoopConfiguration* const loopConfig, const int playerNumber, PlayerConfiguration** playersConfig) {
     this->mapConfig = mapConfig;
     this->judgerConfig = judgerConfig;
     this->loopConfig = loopConfig;
     this->playersConfig = playersConfig;
     this->playerNumber = playerNumber;
}

GameConfiguration::~GameConfiguration() {
    delete [] mapConfig;
    delete [] judgerConfig;
    delete [] loopConfig;
    for(int i=0; i<playerNumber; ++i){
        delete [] playersConfig[i];
    }
}

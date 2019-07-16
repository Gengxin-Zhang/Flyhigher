/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "GameConfiguration.h"
using std::to_string, std::invalid_argument;

/**
 * GameConfiguration implementation
 */

shared_ptr<MapConfiguration> GameConfiguration::getMapConfig() const{
    return mapConfig;
}

shared_ptr<JudgerConfiguration> GameConfiguration::getJudgerConfig() const{
    return judgerConfig;
}

shared_ptr<LoopConfiguration> GameConfiguration::getLoopConfig() const{
    return loopConfig;
}

int GameConfiguration::getPlayerNumber() const{
    return playerNumber;
}

shared_ptr<PlayerConfiguration> GameConfiguration::getPlayersConfig(const int index) const{
    if(index < 0 || index >= playerNumber){
        throw invalid_argument("index should not be " + to_string(index));
    }
    return playersConfig[index];
}

GameConfiguration::GameConfiguration(shared_ptr<MapConfiguration> const mapConfig,
                                     shared_ptr<JudgerConfiguration> const judgerConfig,
                                     shared_ptr<LoopConfiguration> const loopConfig,
                                     const int playerNumber,
                                     shared_ptr<PlayerConfiguration>* playersConfig) {
     this->mapConfig = mapConfig;
     this->judgerConfig = judgerConfig;
     this->loopConfig = loopConfig;
     this->playersConfig = playersConfig;
     this->playerNumber = playerNumber;
}

GameConfiguration::~GameConfiguration() {

}

/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "GameConfiguration.h"

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
        throw invalid_argument("index should not be " + index);
    }
    return playersConfig[index];
}

GameConfiguration::GameConfiguration(MapConfiguration* const mapConfig, JudgerConfiguration* const judgerConfig,
 LoopConfiguration* const loopConfig, const int playerNumber, const PlayerConfiguration* const * playersConfig) {
     this->mapConfig = mapConfig;
     this->judgerConfig = judgerConfig;
     this->loopConfig = loopConfig;
     this->playersConfig = playersConfig;
     this->playerNumber = playerNumber;
}

GameConfiguration::~GameConfiguration() {

}
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

shared_ptr<PlayerConfiguration> GameConfiguration::getPlayerConfig() const{
    return playerConfig;
}

GameConfiguration::GameConfiguration(shared_ptr<MapConfiguration> const mapConfig,
                                     shared_ptr<JudgerConfiguration> const judgerConfig,
                                     shared_ptr<LoopConfiguration> const loopConfig,
                                     const int playerNumber,
                                     shared_ptr<PlayerConfiguration> const playerConfig,
                                     shared_ptr<LargeStarConfiguration> const largeStarConfig,
                                     shared_ptr<LittleStarConfiguration> const littleStarConfig) {
     this->mapConfig = mapConfig;
     this->judgerConfig = judgerConfig;
     this->loopConfig = loopConfig;
     this->playerConfig = playerConfig;
     this->playerNumber = playerNumber;
     this->largeStarConfig =largeStarConfig;
     this->littleStarConfig = littleStarConfig;
}

GameConfiguration::~GameConfiguration() {

}

shared_ptr<LargeStarConfiguration> GameConfiguration::getLargeStarConfig() const{
    return largeStarConfig;
}

shared_ptr<LittleStarConfiguration> GameConfiguration::getLittleStarConfig() const{
    return littleStarConfig;
}

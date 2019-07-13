/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Game.h"
#include <exception>
using std::illegal_argument;

/**
 * Game implementation
 */

Game::Game(GameConfiguration* const config) {
    judger = new Judger(config->getJudgerConfig());
    judger->init();
    map = new Map(config->getMapConfig());
    player_num = config->getPlayerNumber();
    for(int i=0; i<player_num; ++i){
        Player* player = new Player(config->getPlayersConfig(i));
        players[player->getName()] = player;
        player->init();
    }
    loop = new Loop(config->getLoopConfig());
    loop->init();
}

Game::~Game() {

}

void Game::run() {
    return;
}

Map* Game::getMap() const{
    return map;
}

Judger* Game::getJudger() const{
    return judger;
}

Loop* Game::getLoop() const{
    return loop;
}

layer* Game::getPlayer(const string name) const{
    //TODO: name不存在的报错
    players[name];
}

int Game::getPlayerNumber() const{
    return player_num;
}
/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Game.h"
#include "../../tools/Logger.h"
#include "../systems/Engine.h"
#include <exception>
using std::invalid_argument;

/**
 * Game implementation
 */

Game::Game(GameConfiguration* const config) {
    Logger* logger = Engine::getInstance()->getLogger();
    logger->infomation("准备一场游戏");
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
    Logger* logger = Engine::getInstance()->getLogger();
    logger->infomation("开始一场游戏");
    loop->run();
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

Player* Game::getPlayer(const string name) {
    //TODO: name不存在的报错
    return players[name];
}

int Game::getPlayerNumber() const{
    return player_num;
}

/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Game.h"
#include "../../tools/Logger.h"
#include "../systems/Engine.h"
#include <exception>
#define log Engine::getInstance()->getLogger()
using std::invalid_argument;

/**
 * Game implementation
 */

Game::Game(GameConfiguration* const config) {
    log->infomation("准备一场游戏");
    judger = std::shared_ptr<Judger>(new Judger(config->getJudgerConfig()));
    map = std::shared_ptr<Map>(new Map(config->getMapConfig()));
    loop = std::shared_ptr<Loop>(new Loop(config->getLoopConfig()));
    player_num = config->getPlayerNumber();
    for(int i=0; i<player_num; ++i){
        std::shared_ptr<Player> player(new Player(config->getPlayersConfig(i), map->getBrithPoint(i)));
        players[player->getName()] = player;
    }
}

Game::~Game() {

}

void Game::run() {
    judger->init();
    for(std::map<string,std::shared_ptr<Player>>::iterator it = players.begin(); it != players.end(); ++it){
        it->second->init();
    }
    log->infomation("开始一场游戏");
    loop->init();
    loop->run();
    log->debug("结束loop");
    delete this;
}

shared_ptr<Map> Game::getMap() const{
    return map;
}

shared_ptr<Judger> Game::getJudger() const{
    return judger;
}

shared_ptr<Loop> Game::getLoop() const{
    return loop;
}

shared_ptr<Player> Game::getPlayer(const string name) {
    return players[name];
}

int Game::getPlayerNumber() const{
    return player_num;
}

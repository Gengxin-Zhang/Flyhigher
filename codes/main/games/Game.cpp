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
    judger = new Judger(config->getJudgerConfig());
    map = new Map(config->getMapConfig());
    loop = new Loop(config->getLoopConfig());
    player_num = config->getPlayerNumber();
    for(int i=0; i<player_num; ++i){
        Player* player = new Player(config->getPlayersConfig(i), map->getBrithPoint(i));
        players[player->getName()] = player;

    }
}

Game::~Game() {
    if(judger) delete judger;
    log->debug("析构judger");
    if(map) delete map;
    log->debug("析构map");
    if(loop) delete loop;
    log->debug("析构loop");
    for(std::map<string, Player*>::iterator it=players.begin(); it!=players.end(); ++it){
        if(it->second) delete [] it->second;
        log->debug("析构" + it->first);
    }
}

void Game::run() {
    judger->init();
    for(std::map<string,Player*>::iterator it = players.begin(); it != players.end(); ++it){
        it->second->init();
    }
    log->infomation("开始一场游戏");
    loop->init();
    loop->run();
    log->debug("结束loop");
    delete this;
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
    return players[name];
}

int Game::getPlayerNumber() const{
    return player_num;
}

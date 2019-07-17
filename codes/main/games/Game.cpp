/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Game.h"
#include "../systems/Engine.h"
#define log Engine::getInstance()->getLogger()

/**
 * Game implementation
 */

Game::Game(shared_ptr<GameConfiguration> const config) {
    log->infomation("准备一场游戏");
    judger = std::shared_ptr<Judger>(new Judger(config->getJudgerConfig()));
    map = std::shared_ptr<Map>(new Map(config->getMapConfig()));
    loop = std::shared_ptr<Loop>(new Loop(config->getLoopConfig()));
    player_num = config->getPlayerNumber();
    tmp_players = new std::shared_ptr<Player>[player_num];
    for(int i=0; i<player_num; ++i){
        std::shared_ptr<Player> player(new Player(config->getPlayerConfig()));
        tmp_players[i] = player;
    }
}

Game::~Game() {

}

void Game::run() {
    judger->init();
    judger->readStartData();
    log->infomation("开始一场游戏");
    for(int i=0; i<player_num; ++i){
        players.insert(make_pair(tmp_players[i]->getUID(), tmp_players[i]));
    }
    delete [] tmp_players;
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

std::map<string, shared_ptr<Player>> Game::getPlayers() {
    return players;
}

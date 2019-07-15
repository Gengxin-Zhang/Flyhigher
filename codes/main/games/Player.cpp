/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Player.h"
#include "./entitys/Carrier.h"
#include "./entitys/Bomber.h"
#include "./entitys/Fighter.h"
#include "../../tools/Logger.h"
#include "../systems/Engine.h"
#include <string>
#include <exception>
using std::to_string, std::invalid_argument;

/**
 * Player implementation
 */

Player::Player(PlayerConfiguration* const config) {
    Logger* logger = Engine::getInstance()->getLogger();
    name = config->getName();
    logger->debug("构造玩家对象：" + name);
    color = config->getColor();
    carrier = new Carrier(this, config->getCarrierConfig());
    for(int i=0; i<3; ++i){
        bombers[i] = new Bomber(this, config->getBomberConfig());
    }
    for(int i=0; i<5; ++i){
        fighters[i] = new Fighter(this, config->getFighterConfig());
    }
}

Player::~Player() {
    delete [] carrier;
    for(int i=0; i<3; ++i){
        delete [] bombers[i];
    }
    for(int i=0; i<5; ++i){
        delete [] fighters[i];
    }
}

void Player::init() {
    Logger* logger = Engine::getInstance()->getLogger();
    logger->debug("初始化玩家：" + name);
    power = 0;
}

void Player::win() {
    Logger* logger = Engine::getInstance()->getLogger();
    logger->infomation("玩家" + name + "胜利");
}

void Player::lose() {
    Logger* logger = Engine::getInstance()->getLogger();
    logger->infomation("玩家" + name + "失败");
}

Carrier* Player::getCarrier() const{
    return carrier;
}

Bomber* Player::getBomber(const int index) const{
    if(index >= 0 && index < 3) return bombers[index];
    else{
        Logger* logger = Engine::getInstance()->getLogger();
        logger->severe("获取轰炸机出错，位置:", index);
        throw invalid_argument("index should not be "+ to_string(index));
    }
}

Fighter* Player::getFighter(const int index) const{
    if(index >= 0 && index < 5) return fighters[index];
    else {
        Logger* logger = Engine::getInstance()->getLogger();
        logger->severe("获取战斗机出错，位置:", index);
        throw invalid_argument("index should not be "+ to_string(index));
    }
}

string Player::getName() const{
    return name;
}

Color Player::getColor() const{
    return color;
}

void Player::addPower(const int power) {
    Logger* logger = Engine::getInstance()->getLogger();
    logger->debug("玩家" + name + "当前资源：", this->power);
    logger->debug("玩家" + name + "获得资源：", power);
    this->power += power;
}

bool Player::subPower(int power) {
    Logger* logger = Engine::getInstance()->getLogger();
    logger->debug("玩家" + name + "当前资源：", this->power);
    logger->debug("玩家" + name + "消耗资源", power);
    if((this->power - power) < 0) return false;
    this->power -= power;
    return true;
}

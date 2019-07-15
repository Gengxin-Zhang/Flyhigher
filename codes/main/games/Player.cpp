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
#include <cmath>
#define log Engine::getInstance()->getLogger()
#define loop Engine::getInstance()->getNowGame()->getLoop()
using std::to_string, std::invalid_argument;

/**
 * Player implementation
 */

Player::Player(PlayerConfiguration* const config, const Point2D startPoint) {
    name = config->getName();
    log->debug("构造玩家对象：" + name);
    color = config->getColor();
    power = 0;
    this->startPoint = startPoint;
    carrier = new Carrier(this, config->getCarrierConfig());
    for(int i=0; i<3; ++i){
        bombers[i] = new Bomber(this, config->getBomberConfig());
    }
    for(int i=0; i<5; ++i){
        fighters[i] = new Fighter(this, config->getFighterConfig());
    }
}

Player::~Player() {
    if(carrier) delete carrier;
    for(int i=0; i<3; ++i){
        if(bombers[i]) delete bombers[i];
    }
    for(int i=0; i<5; ++i){
        if(fighters[i]) delete fighters[i];
    }
}

void Player::init() {
    log->debug("初始化玩家：" + name);
    carrier->setPoint(startPoint);
    carrier->init();
    loop->addLivingEntity(carrier);
    log->debug("添加母舰到玩家对象：" + name);
    Vector2D v1 = Vector2D(0, 100);
    for(int i=0; i<3; ++i){
        bombers[i]->setPoint(v1.toPoint2D(startPoint));
        bombers[i]->init();
        loop->addLivingEntity(bombers[i]);
        v1 = v1.rotate(2*M_PI/3);
    }
    log->debug("添加轰炸机到玩家对象：" + name);
    Vector2D v2 = Vector2D(0, -100);
    for(int i=0; i<5; ++i){
        fighters[i]->setPoint(v2.toPoint2D(startPoint));
        fighters[i]->init();
        loop->addLivingEntity(fighters[i]);
        v2 = v2.rotate(2*M_PI/5);
    }
    log->debug("添加战斗机到玩家对象：" + name);
}

void Player::win() {
    log->infomation("玩家" + name + "胜利");
}

void Player::lose() {
    log->infomation("玩家" + name + "失败");
}

Carrier* Player::getCarrier() const{
    return carrier;
}

Bomber* Player::getBomber(const int index) const{
    if(index >= 0 && index < 3) return bombers[index];
    else{
        log->severe("获取轰炸机出错，位置:", index);
        throw invalid_argument("index should not be "+ to_string(index));
    }
}

Fighter* Player::getFighter(const int index) const{
    if(index >= 0 && index < 5) return fighters[index];
    else {
        log->severe("获取战斗机出错，位置:", index);
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
    log->debug("玩家" + name + "当前资源：", this->power);
    log->debug("玩家" + name + "获得资源：", power);
    this->power += power;
}

bool Player::subPower(int power) {
    log->debug("玩家" + name + "当前资源：", this->power);
    log->debug("玩家" + name + "消耗资源", power);
    if((this->power - power) < 0) return false;
    this->power -= power;
    return true;
}

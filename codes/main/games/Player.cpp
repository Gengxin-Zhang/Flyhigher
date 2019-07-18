/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Player.h"
#include "./entitys/Carrier.h"
#include "./entitys/Bomber.h"
#include "./entitys/Fighter.h"
#include "../systems/Engine.h"
#include <cmath>
#define log Engine::getInstance()->getLogger()
#define loop Engine::getInstance()->getNowGame()->getLoop()
using std::to_string;

/**
 * Player implementation
 */

Player::Player(shared_ptr<PlayerConfiguration> const config): enable_shared_from_this<Player>(){
    log->debug("构造玩家对象：");
    power = 0;
    this->config = config;
}

Player::~Player() {
}

void Player::init(const string uid, const string name, const Color color, const Point2D startPoint) {
    log->debug(startPoint.toString());
    this->name = name;
    this->color = color;
    this->uid = uid;
    this->startPoint = startPoint;
    allowHeal = true;
    isBuilding = false;
    buildStartTick = 0;
    buildEndTick = 0;
    log->debug("初始化玩家：" + name);
    carrier = shared_ptr<Carrier>(new Carrier(shared_from_this(), config->getCarrierConfig()));
    carrier->setPoint(startPoint);
    carrier->init();
    loop->addLivingEntity(carrier);
    log->debug("添加母舰到玩家对象：" + name);
    Vector2D v1 = Vector2D(0, 50);
    for(int i=0; i<3; ++i){
        bombers[i] = shared_ptr<Bomber>(new Bomber(shared_from_this(), config->getBomberConfig()));
        bombers[i]->setPoint(v1.toPoint2D(startPoint));
        bombers[i]->init();
        loop->addLivingEntity(bombers[i]);
        v1 = v1.rotate(2*M_PI/3);
    }
    log->debug("添加轰炸机到玩家对象：" + name);
    Vector2D v2 = Vector2D(0, -50);
    for(int i=0; i<5; ++i){
        fighters[i] = shared_ptr<Fighter>(new Fighter(shared_from_this(), config->getFighterConfig()));
        fighters[i]->setPoint(v2.toPoint2D(startPoint));
        fighters[i]->init();
        loop->addLivingEntity(fighters[i]);
        v2 = v2.rotate(2*M_PI/5);
    }
    fighters[1]->setPoint(Vector2D(-50, 0).toPoint2D(startPoint));
    fighters[4]->setPoint(Vector2D(50, 0).toPoint2D(startPoint));
    log->debug("添加战斗机到玩家对象：" + name);
    lost = false;
}

void Player::win() {
    log->information("玩家" + name + "胜利");
}

void Player::lose() {
    log->information("玩家" + name + "失败");
    lost = true;
}

shared_ptr<Carrier> Player::getCarrier() const{
    return carrier;
}

shared_ptr<Bomber> Player::getBomber(const int uid){
    if(bombers.find(uid) == bombers.end()){
        return nullptr;
    }
    return bombers[uid];
}

shared_ptr<Fighter> Player::getFighter(const int uid){
    if(fighters.find(uid) == fighters.end()){
        return nullptr;
    }
    return fighters[uid];
}

string Player::getName() const{
    return name;
}

Color Player::getColor() const{
    return color;
}

string Player::getUID() const{
    return uid;
}

int Player::getPower() const{
    return power;
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

bool Player::build(){
    if(isBuilding) return false;
    buildStartTick = loop->getNowTick();
    for(int i=0; i<5; ++i){
        if(fighters[i]->isDeath()){
            if(power < fighters[i]->getRebuildPower()){
                return false;
            }
            isBuilding = true;
            buildStartTick = loop->getNowTick();
            buildEndTick = buildStartTick + fighters[i]->getRebuildTicks();
            return true;
        }
    }
    return false;
}

bool Player::isBuildFinished() const {
    if(!isBuilding)return false;
    return loop->getNowTick() >= buildEndTick;
}

void Player::buildCompletely(){
    if(!isBuilding)return;
    isBuilding = false;
    buildStartTick = 0;
    for(int i=0; i<5; ++i){
        if(fighters[i]->isDeath()){
            fighters[i]->init();
            loop->addLivingEntity(fighters[i]);
            return;
        }
    }
}

bool Player::isAllowHeal() const{
    return allowHeal;
}

bool Player::getBuilding() const{
    return isBuilding;
}

void Player::setAllowHeal(const bool allowHeal) {
    this->allowHeal = allowHeal;
}

int Player::getRemainBuildTick() const{
    return buildEndTick - loop->getNowTick();
}

map<int, shared_ptr<Bomber>>  Player::getBombers() const{
    return bombers;
}

map<int, shared_ptr<Fighter>> Player::getFighters() const {
    return fighters;
}

bool Player::isLost() const{
    return lost;
}

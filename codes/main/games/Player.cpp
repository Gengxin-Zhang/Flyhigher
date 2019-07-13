/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Player.h"

/**
 * Player implementation
 */

Player::Player(PlayerConfiguration* const config) {
    name = config->getName();
    color = config->getColor();
}

Player::~Player() {

}

void Player::init() {
    
    return;
}

void Player::win() {
    return;
}

void Player::lose() {
    return;
}

Carrier* Player::getCarrier() const{
    return carrier;
}

Bomber* Player::getBomber(const int index) const{
    if(index >= 0 && index < 3) return bombers[index];
    else ;//TODO: 给个合理的提示，可以是debug的
}

Fighter* Player::getFighter(const int index) const{
    if(index >= 0 && index < 5) return fighters[index];
    else ;//TODO: 给个合理的提示，可以是debug的
}

string Player::getName() const{
    return name;
}

Color Player::getColor() const{
    return color;
}

void Player::addPower(const int power) {
    this->power += power;
}

bool Player::subPower(int power) {
    if((this->power - power) < 0) return false;
    this->power -= power;
    return true;
}
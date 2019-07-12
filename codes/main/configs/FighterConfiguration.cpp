/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "FighterConfiguration.h"

/**
 * FighterConfiguration implementation
 */


int FighterConfiguration::getMaxHealth() const{
    return maxHealth;
}

int FighterConfiguration::getHealRate() const{
    return healRate;
}

int FighterConfiguration::getHealPower() const{
    return healPower;
}

int FighterConfiguration::getSpeed() const{
    return speed;
}

double FighterConfiguration::getBulletRadius() const{
    return bulletRadius;
}

int FighterConfiguration::getBulletDamage() const{
    return bulletDamage;
}

int FighterConfiguration::getBulletSpeed() const{
    return bulletSpeed;
}

int FighterConfiguration::getShootDelay() const{
    return shootDelay;
}

int FighterConfiguration::getRebuildPower() const{
    return rebuildPower;
}

int FighterConfiguration::getRebuildTick() const{
    return rebuildTick;
}

double FighterConfiguration::getFighterRadius() const{
    return fighterRadius;
}

FighterConfiguration::FighterConfiguration(const int maxHealth, const int healRate, const int healPower, const int speed,
        const double bulletRadius, const int bulletDamage, const int bulletSpeed, const int shootDelay, const int rebuildPower,
        const int rebuildTick, const double fighterRadius){
    this->maxHealth = maxHealth;
    this->healRate = healRate;
    this->healPower = healPower;
    this->speed = speed;
    this->bulletRadius = bulletRadius;
    this->bulletDamage = bulletDamage;
    this->bulletSpeed = bulletSpeed;
    this->shootDelay = shootDelay;
    this->rebuildPower = rebuildPower;
    this->rebuildTick = rebuildTick;
    this->fighterRadius = fighterRadius;
}

FighterConfiguration::~FighterConfiguration() {

}
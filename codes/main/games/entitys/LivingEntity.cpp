/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "LivingEntity.h"
#include "../Player.h"
using std::to_string;

/**
 * LivingEntity implementation
 */


LivingEntity::LivingEntity(shared_ptr<Player> const player, shared_ptr<PlaneConfiguration> const config,
 shared_ptr<Entity> const parentEntity, const double x, const double y)
 :MovableEntity(config->getRadius(), Vector2D(0, config->getSpeed()), parentEntity, x, y) {
     this->player = player;
     maxHealth = config->getMaxHealth();
     healRate = config->getHealRate();
     healPower = config->getHealPower();
     this->nowHealth = 0;
}

int LivingEntity::getMaxHealth() const{
    return maxHealth;
}

int LivingEntity::getNowHealth() const{
    return nowHealth;
}

void LivingEntity::heal(const int health) {
    nowHealth += health;
    if(nowHealth > maxHealth) nowHealth = maxHealth;
}

bool LivingEntity::damage(const int damage) {
    nowHealth -= damage;
    if(nowHealth <= 0){
        die();
    }
    return death;
}

void LivingEntity::init() {
    nowHealth = maxHealth;
    death = false;
}

void LivingEntity::die() {
    nowHealth = 0;
    death = true;
}

shared_ptr<Player> LivingEntity::getPlayer() const{
    return player;
}

int LivingEntity::getHealRate() const{
    return healRate;
}

int LivingEntity::getHealPower() const{
    return healPower;
}

LivingEntity::~LivingEntity() {

}

string LivingEntity::getClassName() const{
    return "LivingEntity";
}

string LivingEntity::toString() const{
    return MovableEntity::toString() + "[LivingEntity] (player=" +
            player->getName() + ", nowHealth=" + to_string(nowHealth) + ", maxHealth=" + to_string(maxHealth) +
            ", healRate=" + to_string(healRate) + ", healPower=" + to_string(healPower) + ")";
}

bool LivingEntity::isDeath() const{
    return death;
}

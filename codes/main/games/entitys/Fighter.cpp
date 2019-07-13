/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Fighter.h"

/**
 * Fighter implementation
 */


Fighter::Fighter(Player* const player, FighterConfiguration* const config,
 Entity* const parentEntity, const double x, const double y) 
 :LivingEntity(player, config->getConfig(), parentEntity, x, y) {
    this->isCollecting = false;
    RebuildableConfiguration* rConfig = config->getRebuildConfig();
    this->weapon = new Weapon(config->getWeaponConfig());
    //TODO: 通过配置项构造weapon
}

Fighter::~Fighter() {
    delete [] weapon;
}

void Fighter::die() {
    if(collecting) stopCollecting();
    LivingEntity::die();
}

vector<Entity*> Fighter::see() const{
    //TODO: 思考怎么实现ing
}

bool Fighter::isInSight(const Entity& ano) const{
     //TODO: 思考怎么实现ing
}

bool Fighter::shoot(const double direction) const{
    return weapon->shoot(direction);
}

bool Fighter::isCollecting() const{
    return collecting;
}

void Fighter::collect(ResourceEntity& entity) {
    collectingEntity = &entity;
    collectingEntity->setBeingCollected(true);
    collecting = true;
    //startTime = ;
    //TODO: 添加主时序的当前tick
}

void Fighter::collectCompletely() {
    //TODO: 我方资源值+=采集的资源值
    delete collectingEntity;
    collectingEntity = (ResourceEntity*)0;
    collecting = false;
}

void Fighter::stopCollecting() {
    collecting = false;
    collectingEntity->setBeingCollected(false);
    collectingEntity = (ResourceEntity*)0;
}

long Fighter::getStartTime() const{
    return startTime;
}

int Fighter::getRebuildTicks() const{
    return rebuildTicks;
}

int Fighter::getRebuildPower() const{
    return rebuildPower;
}
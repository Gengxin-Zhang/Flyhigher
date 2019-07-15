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
    this->collecting = false;
    this->weapon = new Weapon(config->getWeaponConfig());
    RebuildableConfiguration* rConfig = config->getRebuildConfig();
    rebuildPower = rConfig->getPower();
    rebuildTicks = rConfig->getTick();
}

Fighter::~Fighter() {
    delete [] weapon;
}

void Fighter::die() {
    if(collecting) stopCollecting();
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

void Fighter::collect(ResourceEntity entity) {
    collectingEntity = &entity;
    collectingEntity->setBeingCollected(true);
    collecting = true;
    //startTime = ;
    //TODO: 添加主时序的当前tick
}

void Fighter::collectCompletely() {
    //TODO: 我方资源值+=采集的资源值
    delete collectingEntity;
    collectingEntity = nullptr;
    collecting = false;
}

void Fighter::stopCollecting() {
    collecting = false;
    collectingEntity->setBeingCollected(false);
    collectingEntity = nullptr;
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

void Fighter::rebuild(){
    //TODO: beginRebuildTick = nowTick;
}

Rebuildable::~Rebuildable(){

}

Collector::~Collector(){

}

string Fighter::getClassName() const{
    return "Fighter";
}

string Fighter::toString() const{
    return LivingEntity::toString() +"[Fighter] ()";
}

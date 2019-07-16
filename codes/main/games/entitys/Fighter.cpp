/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Fighter.h"
#include "../Player.h"
#include <vector>
using std::make_shared;

/**
 * Fighter implementation
 */


Fighter::Fighter(shared_ptr<Player> const player, shared_ptr<FighterConfiguration> const config,
 shared_ptr<Entity> const parentEntity, const double x, const double y)
 :LivingEntity(player, config->getConfig(), parentEntity, x, y) {
    this->collecting = false;
    this->weapon = shared_ptr<Weapon>(new Weapon(config->getWeaponConfig()));
    shared_ptr<RebuildableConfiguration> rConfig = config->getRebuildConfig();
    rebuildPower = rConfig->getPower();
    rebuildTicks = rConfig->getTick();
}

Fighter::~Fighter() {
}

void Fighter::die() {
    if(collecting) stopCollecting();
}

vector<shared_ptr<Entity>> Fighter::see() const{
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
    collectingEntity = make_shared<ResourceEntity>(entity);
    collectingEntity->setBeingCollected(true);
    collecting = true;
    //startTime = ;
    //TODO: 添加主时序的当前tick
}

void Fighter::collectCompletely() {
    //TODO: 我方资源值+=采集的资源值
    shared_ptr<Player> ptr = getPlayer();
    ptr->addPower(collectingEntity->getPower());
    collectingEntity.reset();
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

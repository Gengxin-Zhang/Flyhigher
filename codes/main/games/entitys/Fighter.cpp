/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Fighter.h"
#include "../Player.h"
#include <vector>
#include "../../systems/Engine.h"
#include <cmath>
using std::make_shared, std::cos;
#define loop Engine::getInstance()->getNowGame()->getLoop()

/**
 * Fighter implementation
 */


Fighter::Fighter(shared_ptr<Player> const player, shared_ptr<FighterConfiguration> const config,
 shared_ptr<Entity> const parentEntity, const double x, const double y)
 :LivingEntity(player, config->getConfig(), parentEntity, x, y) {
    this->collecting = false;
    shared_ptr<RebuildableConfiguration> rConfig = config->getRebuildConfig();
    rebuildPower = rConfig->getPower();
    rebuildTicks = rConfig->getTick();
    this->config = config;
}

Fighter::~Fighter() {
}

void Fighter::die() {
    LivingEntity::die();
    if(collecting) stopCollecting();
}

void Fighter::init(){
    LivingEntity::init();
    startTime = 0;
    endTime = 0;
    weapon = shared_ptr<Weapon>(new Weapon(config->getWeaponConfig(), shared_from_this()));
}

bool Fighter::isInSight(const Entity& ano) const{
    if(isMoving()){
        if(getSpeed().getCosineWith(toVector2D(ano)) > 0 && getSpeed().getCosineWith(toVector2D(ano)) < cos(sightAngle)){
                return getDistance(ano) <= longSight;
        }
    }else{
        return getDistance(ano) <= shortSight;
    }
}

bool Fighter::shoot(const double direction) const{
    return weapon->shoot(direction);
}

bool Fighter::isCollecting() const{
    return collecting;
}
bool Fighter::collect(shared_ptr<ResourceEntity> const entity) {
    if(entity->isBeingCollected()) return false;
    if(collecting) return false;
    if(!isOverlapped(*entity) && !isContained(*entity) && !contains(*entity)) return false;
    if(isMoving()) return false;
    collectingEntity = entity;
    collectingEntity->setBeingCollected(true);
    collecting = true;
    startTime = loop->getNowTick();
    endTime = startTime + collectingEntity->getCollectTick();
    return true;
}

void Fighter::collectCompletely() {
    if(!collecting) return;
    shared_ptr<Player> ptr = getPlayer();
    ptr->addPower(collectingEntity->getPower());
    loop->removeResourceEntity(collectingEntity->getUID());
    collecting = false;
}

bool Fighter::collectFinished() const{
    if(!collecting) return false;
    return loop->getNowTick() >= endTime;
}

void Fighter::stopCollecting() {
    if(!collecting) return;
    collecting = false;
    collectingEntity->setBeingCollected(false);
    collectingEntity = nullptr;
    startTime = 0;
    endTime = 0;
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

int Fighter::getRemainTime() const{
    if(!collecting) return 0;
    return collectingEntity->getCollectTick() - (loop->getNowTick() - startTime);
}

Collector::~Collector(){

}

string Fighter::getClassName() const{
    return "Fighter";
}

string Fighter::toString() const{
    return LivingEntity::toString() +"[Fighter] ()";
}

int Fighter::getWeaponCD() const{
    return weapon->getDelay() - (loop->getNowTick() - weapon->getLastShoot());
}

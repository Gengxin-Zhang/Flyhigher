/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Fighter.h"

/**
 * Fighter implementation
 */


Fighter::Fighter(const FighterConfiguration& config): LivingEntity() {
    this->config = config;
    this->isCollecting = false;
    //TODO: 通过配置项调用父类构造函数
    //TODO: 通过配置项构造weapon
}

Fighter::~Fighter() {

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
    return weapon.shoot();
}

bool Fighter::isCollecting() const{
    return collecting;
}

void Fighter::collect(ResourceEntity& entity) {
    collectingEntity = &entity;
    collectingEntity->setBeingCollected(true);
    collecting = true;
    startTime = ;
    //TODO: 添加主时序的当前tick
}

void Fighter::collectCompletely() {
    //TODO: 我方资源值+=采集的资源值
    delete collectingEntity;
    collectingEntity = (ResourceEntity*)0;
    collecting = false
}

void Fighter::stopCollecting() {
    collecting = false;
    collectingEntity->setBeingCollected(false);
    collectingEntity = (ResourceEntity*)0;
}

long Fighter::getStartTime() const{
    return startTime;
}
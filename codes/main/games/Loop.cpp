/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Loop.h"
#include <ctime>
using std::time;

/**
 * Loop implementation
 */

Loop::Loop(LoopConfiguration* const config) {
    maxTickAllowed = config->getMaxTickAllowed();
}

Loop::~Loop() {

}

void Loop::run() {
    return;
}

void Loop::init() {
    nowTick = 0;
    nowTickStartTime = time(0);
}

void Loop::endWithWinner(Player* const winner) {
    return;
}

void Loop::endWithTimeOut() {
    return;
}

long Loop::getMaxTickAllowed() const {
    return maxTickAllowed;
}

void Loop::addResourceEntity(ResourceEntity* const entity){
    allResourceEntity.insert(entity);
}

void Loop::addBullet(Bullet* const entity){
    allBullet.insert(entity);
}

void Loop::addLivingEntity(LivingEntity* const entity){
    allLivingEntity.insert(entity);
}

bool Loop::removeResourceEntity(ResourceEntity* const entity){
    set<ResourceEntity*>::iterator it = allResourceEntity.find(entity);
    if(it == allResourceEntity.end()){
        return false;
    }
    allResourceEntity.erase(it);
    return true;
}

bool Loop::removeBullet(Bullet* const entity){
    set<Bullet*>::iterator it = allBullet.find(entity);
    if(it == allBullet.end()){
        return false;
    }
    allBullet.erase(it);
    return true;
}

bool Loop::removeLivingEntity(LivingEntity* const entity){
    set<LivingEntity*>::iterator it = allLivingEntity.find(entity);
    if(it == allLivingEntity.end()){
        return false;
    }
    allLivingEntity.erase(it);
    return true;
}
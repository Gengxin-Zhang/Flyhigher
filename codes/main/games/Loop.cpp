/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Loop.h"
#include "../../tools/Logger.h"
#include "../systems/Engine.h"
#include <ctime>
#include <thread>
using std::time, std::chrono::duration, std::chrono::duration_cast;
using std::this_thread::sleep_for;

/**
 * Loop implementation
 */

Loop::Loop(LoopConfiguration* const config) {
    Logger* logger = Engine::getInstance()->getLogger();
    logger->debug("构造主循环对象");
    maxTickAllowed = config->getMaxTickAllowed();
    timePerTick = config->getTimePerTick();
}

Loop::~Loop() {

}

void Loop::run() {
    Logger* logger = Engine::getInstance()->getLogger();
    logger->debug("主循环开始");
    while(nowTick <= maxTickAllowed) {
        ++nowTick;
        logger->debug("现在tick：", nowTick);
        nowTickStartTime = steady_clock::now();
        //TODO: doSomething
        duration<double> time_span = duration_cast<duration<double>>(steady_clock::now() - nowTickStartTime);
        milliseconds deltatime = duration_cast<milliseconds>(time_span);
        if(deltatime < timePerTick){
           sleep_for(timePerTick - deltatime);
        }

    }
    endWithTimeOut();
}

void Loop::init() {
    Logger* logger = Engine::getInstance()->getLogger();
    logger->debug("主循环初始化");
    nowTick = 0;
}

void Loop::endWithWinner(Player* const winner) {
    Logger* logger = Engine::getInstance()->getLogger();
    logger->infomation("游戏结束！");
    logger->debug("存在玩家胜利的游戏结束");
    winner->win();
}

void Loop::endWithTimeOut() {
    Logger* logger = Engine::getInstance()->getLogger();
    logger->infomation("游戏结束！");
    logger->debug("时间用尽的游戏结束");
    //TODO: 没实现
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

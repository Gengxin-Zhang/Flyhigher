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
#include <string>
#include <cmath>
#include<random>
#define log Engine::getInstance()->getLogger()
#define mapp Engine::getInstance()->getNowGame()->getMap()
using std::time, std::chrono::duration, std::chrono::duration_cast;
using std::this_thread::sleep_for, std::to_string;
using std::min, std::make_pair;

/**
 * Loop implementation
 */

Loop::Loop(shared_ptr<LoopConfiguration> const config) {
    log->debug("构造主循环对象");
    maxTickAllowed = config->getMaxTickAllowed();
    timePerTick = config->getTimePerTick();
    allEntity = std::map<int,shared_ptr<Entity>>();
    allResourceEntity = std::map<int,shared_ptr<ResourceEntity>>();
    allBullet = std::map<int,shared_ptr<Bullet>>();
    allLivingEntity = std::map<int,shared_ptr<LivingEntity>>();
}

Loop::~Loop() {
}

void Loop::run() {
    log->debug("主循环开始");
    std::default_random_engine e(time(0));
    std::uniform_real_distribution<double> u(-M_PI,M_PI);
    while(nowTick < maxTickAllowed) {
        ++nowTick;
        log->debug("现在tick：", nowTick);
        nowTickStartTime = steady_clock::now();
        //TODO: doSomething
        //运动
        log->debug("进入运动状态");
        for(auto &le: allLivingEntity){
            le.second->goNextTick();
        }
        for(auto &b: allBullet){
            b.second->goNextTick();
        }
        //边界检测：出界的实体强制设定在界内最近点
        log->debug("边界检测活实体");
        for(auto &le: allLivingEntity){
            if(!mapp->isEntityInMap(*le.second)){
                if((le.second)->getX()<0){
                    (le.second)->setX(0);
                }else if((le.second)->getX()>mapp->getWidth()){
                    (le.second)->setX(mapp->getWidth());
                }
                if((le.second)->getY()<0){
                    (le.second)->setY(0);
                }else if((le.second)->getY()>mapp->getHeight()){
                    (le.second)->setY(mapp->getHeight());
                }
            }
        }
        //边界检测：出界的子弹删除
        log->debug("边界检测子弹");
        for(auto &b: allBullet){
            if(!mapp->isEntityInMap(*b.second)){
                removeBullet(b.first);
            }
        }
        //碰撞检测：任何实体和资源实体都不会相撞
        //碰撞检测：活实体撞活实体，必定至少有一个gg，另一个掉这么多血
        log->debug("碰撞检测实体和实体");
        for(set<shared_ptr<LivingEntity>>::iterator livingEntity=allLivingEntity.begin(); livingEntity!=allLivingEntity.end(); ++livingEntity){
            for1_living_entity_living_entity_begin:
            for(set<shared_ptr<LivingEntity>>::iterator livingEntity2=livingEntity; livingEntity2!=allLivingEntity.end(); ++livingEntity2){
                for1_living_entity_living_entity_2_begin:
                if(livingEntity == livingEntity2){
                    continue;
                }
                if((*livingEntity)->isOverlapped(**livingEntity2) || (*livingEntity)->contains(**livingEntity2) || (*livingEntity)->isContained(**livingEntity2)){
                    log->debug((*livingEntity)->toString() + "碰撞" + (*livingEntity2)->toString());
                    int lowHealth = min((*livingEntity)->getNowHealth(), (*livingEntity2)->getNowHealth());
                    bool d1 = (*livingEntity)->damage(lowHealth);
                    log->debug("d1", d1);
                    bool d2 = (*livingEntity2)->damage(lowHealth);
                    log->debug("d2", d2);
                    if(d1 && d2){
                        livingEntity = allLivingEntity.erase(livingEntity);
                        livingEntity2 = allLivingEntity.erase(livingEntity2);
                    }else if(d1){
                        livingEntity = allLivingEntity.erase(livingEntity);
                    }else if(d2){
                        livingEntity2 = allLivingEntity.erase(livingEntity2);
                    }else{
                        log->severe("不可能的结果:碰撞没有任何一方的死亡");
                    }
                    if(livingEntity == allLivingEntity.end()) goto for1_living_entity_living_entity_end;
                    else if(livingEntity2 == allLivingEntity.end()) goto for1_living_entity_living_entity_begin;
                    else goto for1_living_entity_living_entity_2_begin;
                }
            }
        }
        for1_living_entity_living_entity_end:
        //碰撞检测：子弹碰子弹，子弹消失
        log->debug("碰撞检测子弹和子弹");
        for(set<shared_ptr<Bullet>>::iterator bullet=allBullet.begin(); bullet!=allBullet.end(); ++bullet){
            for2_bullet_bullet_begin:
            for(set<shared_ptr<Bullet>>::iterator bullet2=bullet; bullet2!=allBullet.end(); ++bullet2){
                for2_bullet_bullet_2_begin:
                if(bullet == bullet2)continue;
                if((*bullet)->isOverlapped(**bullet2) || (*bullet)->contains(**bullet2) || (*bullet)->isContained(**bullet2)){
                    log->debug((*bullet)->toString() + "碰撞" + (*bullet2)->toString());
                    bullet = allBullet.erase(bullet);
                    if(bullet == bullet2) ++bullet;
                    bullet2 = allBullet.erase(bullet2);
                    if(bullet == allBullet.end()) goto for_bullet_bullet_end;
                    else if(bullet2 == allBullet.end()) goto for2_bullet_bullet_begin;
                    else goto for2_bullet_bullet_2_begin;
                }
            }
        }
        for_bullet_bullet_end:
        //碰撞检测：子弹碰活实体，子弹消失，活实体受伤害
        log->debug("碰撞检测子弹和实体");
        for(set<shared_ptr<Bullet>>::iterator bullet=allBullet.begin(); bullet!=allBullet.end(); ++bullet){
            for3_bullet_living_entity_begin:
            for(set<shared_ptr<LivingEntity>>::iterator livingEntity=allLivingEntity.begin(); livingEntity!=allLivingEntity.end(); ++livingEntity){
                // for3_bullet_living_entity_begin2:
                if((*bullet)->getParentEntity() == (*livingEntity)){
                    continue;
                }
                if((*livingEntity)->isOverlapped(**bullet) || (*livingEntity)->contains(**bullet) || (*livingEntity)->isContained(**bullet)){
                    log->debug((*livingEntity)->toString() + "碰撞" + (*bullet)->toString());
                    if((*bullet)->damageTo(**livingEntity)){
                        livingEntity = allLivingEntity.erase(livingEntity);
                    }
                    bullet = allBullet.erase(bullet);
                    if(bullet == allBullet.end()) goto for3_bullet_living_entity_end;
                    else  goto for3_bullet_living_entity_begin;
                }
            }
        }
        for3_bullet_living_entity_end:
        //射击
        log->debug("射击触发");
        for(set<shared_ptr<LivingEntity>>::iterator le=allLivingEntity.begin(); le!=allLivingEntity.end(); ++le){
            if((*le)->shoot(u(e))){
                log->debug((*le)->toString()+ "射击");
            }
        }
        //坐标处理
        log->debug("坐标处理");
        char graph[50][100];
        memset(graph, 0, 5000);
        for(set<shared_ptr<ResourceEntity>>::iterator it=allResourceEntity.begin(); it!=allResourceEntity.end(); ++it){
            log->debug("resourceEntity loc["+ to_string((*it)->getX()) + "," + to_string((*it)->getY()) + "]");
            graph[50-int((*it)->getY())/10][int((*it)->getX())/10] = 1;
        }
        for(set<shared_ptr<LivingEntity>>::iterator it=allLivingEntity.begin(); it!=allLivingEntity.end(); ++it){
            log->debug("livingEntity loc["+ to_string((*it)->getX()) + "," + to_string((*it)->getY()) + "]  health=" + to_string((*it)->getNowHealth()));
            if((*it)->getClassName() == "Carrier"){
                graph[50-int((*it)->getY())/10][int((*it)->getX())/5] = 'C';
                graph[50-int((*it)->getY())/10 - int((*it)->getRadius()/10)][int((*it)->getX())/5] = '-';
                graph[50-int((*it)->getY())/10 + int((*it)->getRadius()/10)][int((*it)->getX())/5] = '-';
                graph[50-int((*it)->getY())/10][int((*it)->getX())/5 - int((*it)->getRadius()/5)] = '|';
                graph[50-int((*it)->getY())/10][int((*it)->getX())/5 + int((*it)->getRadius()/5)] = '|';
            } else if((*it)->getClassName() == "Bomber"){
                graph[50-int((*it)->getY())/10][int((*it)->getX())/5] = 'B';
                graph[50-int((*it)->getY())/10 - int((*it)->getRadius()/10)][int((*it)->getX())/5] = '-';
                graph[50-int((*it)->getY())/10 + int((*it)->getRadius()/10)][int((*it)->getX())/5] = '-';
                graph[50-int((*it)->getY())/10][int((*it)->getX())/5 - int((*it)->getRadius()/5)] = '|';
                graph[50-int((*it)->getY())/10][int((*it)->getX())/5 + int((*it)->getRadius()/5)] = '|';
            } else if((*it)->getClassName() == "Fighter"){
                graph[50-int((*it)->getY())/10][int((*it)->getX())/5] = 'F';
                graph[50-int((*it)->getY())/10 - int((*it)->getRadius()/10)][int((*it)->getX())/5] = '-';
                graph[50-int((*it)->getY())/10 + int((*it)->getRadius()/10)][int((*it)->getX())/5] = '-';
                graph[50-int((*it)->getY())/10][int((*it)->getX())/5 - int((*it)->getRadius()/5)] = '|';
                graph[50-int((*it)->getY())/10][int((*it)->getX())/5 + int((*it)->getRadius()/5)] = '|';
            } else {
                log->debug("??????????");
            }
        }
        for(set<shared_ptr<Bullet>>::iterator it=allBullet.begin(); it!=allBullet.end(); ++it){
            log->debug("bullet loc["+ to_string((*it)->getX()) + "," + to_string((*it)->getY()) + "]");
            graph[50-int((*it)->getY())/10][int((*it)->getX())/5] = 'o';
        }
        for(int i=0;i<102;++i){
            std::cout<<'-';
            log->getOut()<<'-';
        }
        std::cout<<std::endl;
        log->getOut()<<std::endl;
        for(int i=0;i<50;++i){
            std::cout<<'|';
            log->getOut()<<'|';
            for(int j=0;j<100;++j){
                if(!graph[i][j]){
                    log->getOut()<<'x';
                    std::cout<<'x';
                }else{
                    std::cout<<graph[i][j];
                    log->getOut()<<graph[i][j];
                }
            }
            std::cout<<'|'<<std::endl;
            log->getOut()<<'|'<<std::endl;
        }
        for(int i=0;i<102;++i){
            std::cout<<'-';
            log->getOut()<<'-';
        }
        std::cout<<std::endl;
        log->getOut()<<std::endl;
        duration<double> time_span = duration_cast<duration<double>>(steady_clock::now() - nowTickStartTime);
        milliseconds deltatime = duration_cast<milliseconds>(time_span);
        if(deltatime < timePerTick){
           sleep_for(timePerTick - deltatime);
        }

    }
    endWithTimeOut();
}

void Loop::init() {
    log->debug("主循环初始化");
    nowTick = 0;

}

void Loop::endWithWinner(shared_ptr<Player> const winner) {
    log->infomation("游戏结束！");
    log->debug("存在玩家胜利的游戏结束");
    winner->win();
}

void Loop::endWithTimeOut() {
    log->infomation("游戏结束！");
    log->debug("时间用尽的游戏结束");
}

long Loop::getMaxTickAllowed() const {
    return maxTickAllowed;
}

void Loop::addResourceEntity(shared_ptr<ResourceEntity> const entity){
    log->debug("添加资源实体");
    allResourceEntity.insert(make_pair(entity->getUID(), entity));
    allEntity.insert(make_pair(entity->getUID(), entity));
}


void Loop::addBullet(shared_ptr<Bullet> const entity){
    log->debug("添加子弹实体");
    allBullet.insert(make_pair(entity->getUID(), entity));
    allEntity.insert(make_pair(entity->getUID(), entity));
}

void Loop::addLivingEntity(shared_ptr<LivingEntity> const entity){
    log->debug("添加活实体");
    allLivingEntity.insert(make_pair(entity->getUID(), entity));
    allEntity.insert(make_pair(entity->getUID(), entity));
}

bool Loop::removeResourceEntity(const int uid){
    if(allResourceEntity.find(uid)==allResourceEntity.end()) return false;
    log->debug("删除资源实体");
    allEntity.erase(uid);
    allResourceEntity.erase(uid);
    return true;
}

bool Loop::removeBullet(const int uid){
    if(allBullet.find(uid) == allBullet.end()) return false;
    log->debug("删除子弹实体");
    allEntity.erase(uid);
    allBullet.erase(uid);
    return true;
}

bool Loop::removeLivingEntity(const int uid){
    if(allLivingEntity.find(uid) == allLivingEntity.end()) return false;
    log->debug("删除活实体");
    allEntity.erase(uid);
    allLivingEntity.erase(uid);
    return true;
}

shared_ptr<ResourceEntity> Loop::findResourceEntity(const int uid){
    if(allResourceEntity.find(uid) == allResourceEntity.end()) return nullptr;
    else return allResourceEntity[uid];
}

shared_ptr<Bullet> Loop::findBullet(const int uid) {
    if(allBullet.find(uid) == allBullet.end()) return nullptr;
    else return allBullet[uid];
}

shared_ptr<LivingEntity> Loop::findLivingEntity(const int uid) {
    if(allLivingEntity.find(uid) == allLivingEntity.end()) return nullptr;
    else return allLivingEntity[uid];
}

shared_ptr<Entity> Loop::findEntity(const int uid) {
    if(allEntity.find(uid) == allEntity.end()) return nullptr;
    else return allEntity[uid];
}

long Loop::getNowTick() const{
    return nowTick;
}

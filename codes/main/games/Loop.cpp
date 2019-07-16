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
#include <map>
#include<random>
#define log Engine::getInstance()->getLogger()
#define mapp Engine::getInstance()->getNowGame()->getMap()
using std::time, std::chrono::duration, std::chrono::duration_cast;
using std::this_thread::sleep_for, std::to_string;
using std::min, std::map, std::make_pair;

/**
 * Loop implementation
 */

Loop::Loop(shared_ptr<LoopConfiguration> const config) {
    log->debug("构造主循环对象");
    maxTickAllowed = config->getMaxTickAllowed();
    timePerTick = config->getTimePerTick();
    allBullet = set<shared_ptr<Bullet>>();
    allLivingEntity = set<shared_ptr<LivingEntity>>();
    allResourceEntity = set<shared_ptr<ResourceEntity>>();
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
        for(set<shared_ptr<LivingEntity>>::iterator le=allLivingEntity.begin(); le!=allLivingEntity.end(); ++le){
            (*le)->turnDirection(u(e));
            (*le)->goNextTick();
        }
        for(set<shared_ptr<Bullet>>::iterator it=allBullet.begin(); it!=allBullet.end(); ++it){
            (*it)->goNextTick();
        }
        //碰撞检测：任何实体和资源实体都不会相撞
        //碰撞检测：活实体撞活实体，必定至少有一个gg，另一个掉这么多血
        for(set<shared_ptr<LivingEntity>>::iterator le=allLivingEntity.begin(); le!=allLivingEntity.end(); ++le){
            for(set<shared_ptr<LivingEntity>>::iterator le2=le; le2!=allLivingEntity.end(); ++le2){
                if(le == le2){
                    continue;
                }
                if((*le)->isOverlapped(**le2) || (*le)->contains(**le2) || (*le)->isContained(**le2)){
                    log->debug((*le)->toString() + "碰撞" + (*le2)->toString());
                    int lowHealth = min((*le)->getNowHealth(), (*le2)->getNowHealth());
                    bool d1 = (*le)->damage(lowHealth);
                    log->debug("d1", d1);
                    bool d2 = (*le2)->damage(lowHealth);
                    log->debug("d2", d2);
                    if(d1 && d2){
                        le = allLivingEntity.erase(le);
                        --le;
                        le2 = allLivingEntity.erase(le2);
                        goto cont;
                    }else if(d1){
                        le = allLivingEntity.erase(le);
                        --le;
                        goto cont;
                    }else if(d2){
                        le2 = allLivingEntity.erase(le2);
                        --le2;
                    }else{
                        log->severe("不可能的结果:碰撞没有任何一方的死亡");
                    }
                }
            }
            cont:;
        }
        //碰撞检测：子弹碰子弹，子弹消失
        for(set<shared_ptr<Bullet>>::iterator it=allBullet.begin(); it!=allBullet.end(); ++it){
            for(set<shared_ptr<Bullet>>::iterator it2=it; it2!=allBullet.end(); ++it2){
                if(it == it2)continue;
                if((*it)->isOverlapped(**it) || (*it)->contains(**it) || (*it)->isContained(**it)){
                    log->debug((*it)->toString() + "碰撞" + (*it2)->toString());
                    it = allBullet.erase(it);
                    --it;
                    it2 = allBullet.erase(it2);
                    --it2;
                }
            }
        }
        //碰撞检测：子弹碰活实体，子弹消失，活实体受伤害
        for(set<shared_ptr<Bullet>>::iterator it=allBullet.begin(); it!=allBullet.end(); ++it){
            for(set<shared_ptr<LivingEntity>>::iterator le=allLivingEntity.begin(); le!=allLivingEntity.end(); ++le){
                if((*le)->isOverlapped(**it) || (*le)->contains(**it) || (*le)->isContained(**it)){
                    log->debug((*le)->toString() + "碰撞" + (*it)->toString());
                    if((*it)->damageTo(**le)){
                        le = allLivingEntity.erase(le);
                    }
                    it = allBullet.erase(it);
                    --it;
                    goto contt;
                }
            }
            contt:;
        }
        //边界检测：出界的实体强制设定在界内最近点
        for(set<shared_ptr<LivingEntity>>::iterator le=allLivingEntity.begin(); le!=allLivingEntity.end(); ++le){
            if(!mapp->isEntityInMap(**le)){
                if((*le)->getX()<0){
                    (*le)->setX(0);
                }else if((*le)->getX()>mapp->getWidth()){
                    (*le)->setX(mapp->getWidth());
                }
                if((*le)->getY()<0){
                    (*le)->setY(0);
                }else if((*le)->getY()>mapp->getHeight()){
                    (*le)->setY(mapp->getHeight());
                }
            }
        }
        //边界检测：出界的子弹删除
        for(set<shared_ptr<Bullet>>::iterator it=allBullet.begin(); it!=allBullet.end(); ++it){
            if(!mapp->isEntityInMap(**it)){
                it = allBullet.erase(it);
                --it;
            }
        }
        //坐标处理
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
            graph[50-int((*it)->getY())/10][int((*it)->getX())/10] = 1;
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
    allResourceEntity.insert(entity);
}

void Loop::addBullet(shared_ptr<Bullet> const entity){
    log->debug("添加子弹实体");
    allBullet.insert(entity);
}

void Loop::addLivingEntity(shared_ptr<LivingEntity> const entity){
    log->debug("添加活实体");
    allLivingEntity.insert(entity);
}

bool Loop::removeResourceEntity(shared_ptr<ResourceEntity> const entity){
    log->debug("删除资源实体");
    set<shared_ptr<ResourceEntity>>::iterator it = allResourceEntity.find(entity);
    if(it == allResourceEntity.end()){
        return false;
    }
    allResourceEntity.erase(it);
    return true;
}

bool Loop::removeBullet(shared_ptr<Bullet> const entity){
    log->debug("删除子弹实体");
    set<shared_ptr<Bullet>>::iterator it = allBullet.find(entity);
    if(it == allBullet.end()){
        return false;
    }
    allBullet.erase(it);
    return true;
}

bool Loop::removeLivingEntity(shared_ptr<LivingEntity> const entity){
    log->debug("删除活实体");
    set<shared_ptr<LivingEntity>>::iterator it = allLivingEntity.find(entity);
    if(it == allLivingEntity.end()){
        return false;
    }
    allLivingEntity.erase(it);
    return true;
}

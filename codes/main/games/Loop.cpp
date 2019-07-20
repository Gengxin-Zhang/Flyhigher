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
#include <algorithm>
#define log Engine::getInstance()->getLogger()
#define mapp Engine::getInstance()->getNowGame()->getMap()
#define game Engine::getInstance()->getNowGame()
#define judger Engine::getInstance()->getNowGame()->getJudger()
#define config Configuration::getInstance()->getGameConfiguration()
#define le_iter map<int,shared_ptr<LivingEntity>>::iterator
#define b_iter map<int,shared_ptr<Bullet>>::iterator
#define re_iter map<int,shared_ptr<ResourceEntity>>::iterator
using std::time, std::chrono::duration, std::chrono::duration_cast;
using std::this_thread::sleep_for, std::to_string;
using std::min, std::make_pair, std::max, std::dynamic_pointer_cast;

/**
 * Loop implementation
 */

Loop::Loop(shared_ptr<LoopConfiguration> const loop_config) {
    log->debug("构造主循环对象");
    maxTickAllowed = loop_config->getMaxTickAllowed();
    timePerTick = loop_config->getTimePerTick();
    allEntity = std::map<int,shared_ptr<Entity>>();
    allResourceEntity = std::map<int,shared_ptr<ResourceEntity>>();
    allBullet = std::map<int,shared_ptr<Bullet>>();
    allLivingEntity = std::map<int,shared_ptr<LivingEntity>>();
}

Loop::~Loop() {
}

void Loop::edgeCheckForALivingEntity(pair<int, shared_ptr<LivingEntity>> p){
    LivingEntity& le = *p.second;
    if(!mapp->isEntityInMap(le)){
        if(le.getX()<0){
            le.setX(0);
        }else if(le.getX()>mapp->getWidth()){
            le.setX(mapp->getWidth());
        }
        if(le.getY()<0){
            le.setY(0);
        }else if(le.getY()>mapp->getHeight()){
            le.setY(mapp->getHeight());
        }
    }
}

void Loop::edgeCheckForLivingEntity(){
    log->debug("边界检测活实体");
    for_each(allLivingEntity.begin(), allLivingEntity.end(), edgeCheckForALivingEntity);
}

void Loop::moveNextTick(){
    static std::default_random_engine e;
    static std::uniform_real_distribution<double> u(-M_PI, M_PI);
    log->debug("进入运动状态");
    for(auto &le: allLivingEntity){
//        le.second->setMoving(true);
//        le.second->turnDirection(u(e));
        log->debug("射击成功：", le.second->shoot(u(e)));
        if(le.second->isMoving())
            le.second->goNextTick();
    }
    for(auto &b: allBullet){
        b.second->goNextTick();
    }
}

void Loop::edgeCheckForBullet(){
    log->debug("边界检测子弹");
    for(b_iter b=allBullet.begin(); b!=allBullet.end(); ++b){
        if(!mapp->isEntityInMap(*(b->second))){
            log->debug("删除子弹Entity-" + to_string(b->second->getUID()));
            allBullet.erase(b++);
            if(b == allBullet.end()) break;
        }
    }
}

void Loop::impactCheckForLivingEntityAndLivingEntity(){
    log->debug("碰撞检测实体和实体");
    for(le_iter le1=allLivingEntity.begin(); le1!=allLivingEntity.end(); ++le1){
        for_le_le_out_begin:
        for(le_iter le2=le1; le2!=allLivingEntity.end(); ++le2){
            for_le_le_in_begin:
            if(le1 == le2){
                continue;
            }
            shared_ptr<LivingEntity> ptr_le1=le1->second, ptr_le2=le2->second;
            if(ptr_le1->isOverlapped(*ptr_le2) || ptr_le1->contains(*ptr_le2) || ptr_le1->isContained(*ptr_le2)){
                log->debug(ptr_le1->toString() + "碰撞" + ptr_le2->toString());
                if(ptr_le1->getPlayer() == ptr_le2->getPlayer()){
                    double dis = ptr_le1->getDistance(*ptr_le2);
                    double maxr = ptr_le1->getRadius() + ptr_le2->getRadius();
                    double mov = maxr - dis;
                    Vector2D mov1 = Vector2D(mov, ptr_le1->getSpeed().reverse());
                    Vector2D mov2 = Vector2D(mov, ptr_le2->getSpeed().reverse());
                    if(mov1.getCosineWith(ptr_le1->getSpeed()) > 0) ptr_le1->move(mov1);
                    if(mov2.getCosineWith(ptr_le2->getSpeed()) > 0) ptr_le2->move(mov2);
                    continue;
                }
                int lowHealth = min(ptr_le1->getNowHealth(), ptr_le2->getNowHealth());
                bool d1 = ptr_le1->damage(lowHealth);
                bool d2 = ptr_le2->damage(lowHealth);
                if(d1 && d2){
                    allLivingEntity.erase(le1++);
                    if(le1 == le2) ++le1;
                    allLivingEntity.erase(le2++);
                    if(le1 == allLivingEntity.end()) return;
                    else if(le2 == allLivingEntity.end()) goto for_le_le_out_begin;
                    else goto for_le_le_in_begin;
                }else if(d1){
                    allLivingEntity.erase(le1++);
                    if(le1 == allLivingEntity.end()) return;
                    else goto for_le_le_out_begin;
                }else if(d2){
                    allLivingEntity.erase(le2++);
                    if(le2 == allLivingEntity.end()) break;
                    else goto for_le_le_in_begin;
                }else{
                    log->severe("不可能的结果:碰撞没有任何一方的死亡");
                }
            }
        }
    }
}

void Loop::impactCheckForBulletAndBullet(){
    log->debug("碰撞检测子弹和子弹");
    for(b_iter b1=allBullet.begin(); b1!=allBullet.end(); ++b1){
        for_b_b_out_begin:
        for(b_iter b2=b1; b2!=allBullet.end(); ++b2){
            for_b_b_in_begin:
            if(b1 == b2){
                continue;
            }
            shared_ptr<Bullet> ptr_b1=b1->second, ptr_b2=b2->second;
            if(ptr_b1->isOverlapped(*ptr_b2) || ptr_b1->contains(*ptr_b2) || ptr_b1->isContained(*ptr_b2)){
                log->debug(ptr_b1->toString() + "碰撞" + ptr_b2->toString());
                if(ptr_b1->getDamage() == config->getPlayerConfig()->getCarrierConfig()->getNukeConfig()->getAoeDamage()){
                    nuke_boom(ptr_b1);
                }
                if(ptr_b2->getDamage() == config->getPlayerConfig()->getCarrierConfig()->getNukeConfig()->getAoeDamage()){
                    nuke_boom(ptr_b2);
                }
                allBullet.erase(b1++);
                log->debug("删除子弹Entity-" + to_string(ptr_b1->getUID()));
                if(b1 == b2){
                    ++b1;
                }
                allBullet.erase(b2++);
                log->debug("删除子弹Entity-" + to_string(ptr_b2->getUID()));
                if(b1 == allBullet.end()) return;
                else if(b2 == allBullet.end()) goto for_b_b_out_begin;
                else goto for_b_b_in_begin;
            }
        }
    }
}

void Loop::nuke_boom(shared_ptr<Bullet> const nuke){
    shared_ptr<NukeConfiguration> nukeConfig = config->getPlayerConfig()->getCarrierConfig()->getNukeConfig();
    for(le_iter le=allLivingEntity.begin(); le!=allLivingEntity.end(); ++le){
        shared_ptr<LivingEntity> ptr_le = le->second;
        if(ptr_le->getDistance(*nuke) < nukeConfig->getAoeDamageRadius()){
            if(ptr_le->damage(int(nuke->getDamage() - ptr_le->getDistance(*nuke) * nukeConfig->getDamageDecrease()))){
                log->debug(ptr_le->toString() + "死亡");
                allLivingEntity.erase(le++);
                if(le == allLivingEntity.end()){
                    break;
                }
            }
        }
    }
}

void Loop::impactCheckForBulletAndLivingEntity(){
    log->debug("碰撞检测子弹和实体");
    for(b_iter b=allBullet.begin(); b!=allBullet.end(); ++b){
        for_b_le_out_begin:
        for(le_iter le=allLivingEntity.begin(); le!=allLivingEntity.end(); ++le){
//            for_b_le_in_begin:
            shared_ptr<Bullet> ptr_b = b->second;
            shared_ptr<LivingEntity> ptr_le = le->second;
            if(ptr_b->getParentEntity() == ptr_le){
                log->debug(ptr_le->toString() + "未碰撞" + ptr_b->toString());
                continue;
            }
            if(ptr_le->isOverlapped(*ptr_b) || ptr_le->contains(*ptr_b) || ptr_le->isContained(*ptr_b)){
                log->debug(ptr_le->toString() + "碰撞" + ptr_b->toString());
                if(ptr_b->damageTo(*ptr_le)){
                    log->debug(ptr_le->toString() + "死亡");
                    allLivingEntity.erase(le++);
                }
                if(ptr_b->getDamage() == config->getPlayerConfig()->getCarrierConfig()->getNukeConfig()->getAoeDamage()){
                    nuke_boom(ptr_b);
                }
                allBullet.erase(b++);
                log->debug("删除子弹Entity-" + to_string(ptr_b->getUID()));
                if(b == allBullet.end()) return;
                else goto for_b_le_out_begin;
            }
        }
    }
}

void Loop::showInText() const{
    if(!Engine::getInstance()->isDebugMode()){
            return;
    }
    log->debug("文字图形显示");
    char graph[60][120];
    memset(graph, 0, 7200);
    int xstart = 5;
    int ystart = 10;
    for(auto &re: allResourceEntity){
        shared_ptr<ResourceEntity> ptr_re = re.second;
        log->debug("resourceEntity loc["+ to_string(ptr_re->getX()) + "," + to_string(ptr_re->getY()) + "]");
        graph[xstart + 50-int(ptr_re->getY())/10][ystart + int(ptr_re->getX())/5] = 'R';
    }
    for(auto &le: allLivingEntity){
        shared_ptr<LivingEntity> ptr_le = le.second;
        log->debug("livingEntity loc["+ to_string(ptr_le->getX()) + "," + to_string(ptr_le->getY()) + "]  health=" + to_string(ptr_le->getNowHealth()));
        if(ptr_le->getClassName() == "Carrier"){
            graph[xstart + 50-int(ptr_le->getY())/10][ystart + int(ptr_le->getX())/5] = 'C';
            graph[xstart + 50-int(ptr_le->getY())/10 - int(ptr_le->getRadius()/10)][ystart + int(ptr_le->getX())/5] = '-';
            graph[xstart + 50-int(ptr_le->getY())/10 + int(ptr_le->getRadius()/10)][ystart + int(ptr_le->getX())/5] = '-';
            graph[xstart + 50-int(ptr_le->getY())/10][ystart + int(ptr_le->getX())/5 - int(ptr_le->getRadius()/5)] = '|';
            graph[xstart + 50-int(ptr_le->getY())/10][ystart + int(ptr_le->getX())/5 + int(ptr_le->getRadius()/5)] = '|';
        } else if(ptr_le->getClassName() == "Bomber"){
            graph[xstart + 50-int(ptr_le->getY())/10][ystart + int(ptr_le->getX())/5] = 'B';
            graph[xstart + 50-int(ptr_le->getY())/10 - int(ptr_le->getRadius()/10)][ystart + int(ptr_le->getX())/5] = '-';
            graph[xstart + 50-int(ptr_le->getY())/10 + int(ptr_le->getRadius()/10)][ystart + int(ptr_le->getX())/5] = '-';
            graph[xstart + 50-int(ptr_le->getY())/10][ystart + int(ptr_le->getX())/5 - int(ptr_le->getRadius()/5)] = '|';
            graph[xstart + 50-int(ptr_le->getY())/10][ystart + int(ptr_le->getX())/5 + int(ptr_le->getRadius()/5)] = '|';
        } else if(ptr_le->getClassName() == "Fighter"){
            graph[xstart + 50-int(ptr_le->getY())/10][ystart + int(ptr_le->getX())/5] = 'F';
            graph[xstart + 50-int(ptr_le->getY())/10 - int(ptr_le->getRadius()/10)][ystart + int(ptr_le->getX())/5] = '-';
            graph[xstart + 50-int(ptr_le->getY())/10 + int(ptr_le->getRadius()/10)][ystart + int(ptr_le->getX())/5] = '-';
            graph[xstart + 50-int(ptr_le->getY())/10][ystart + int(ptr_le->getX())/5 - int(ptr_le->getRadius()/5)] = '|';
            graph[xstart + 50-int(ptr_le->getY())/10][ystart + int(ptr_le->getX())/5 + int(ptr_le->getRadius()/5)] = '|';
        } else {
            log->severe("不可能看到这个！");
        }
    }
    for(auto &b: allBullet){
        shared_ptr<Bullet> ptr_b = b.second;
        log->debug("bullet loc["+ to_string(ptr_b->getX()) + "," + to_string(ptr_b->getY()) + "]");
        graph[xstart + 50-int(ptr_b->getY())/10][ystart + int(ptr_b->getX())/5] = 'o';
    }
    for(int i=0;i<122;++i){
        std::cout<<'-';
        log->getOut()<<'-';
    }
    std::cout<<std::endl;
    log->getOut()<<endl;
    for(int i=0;i<60;++i){
        std::cout<<'|';
        log->getOut()<<'|';
        for(int j=0;j<120;++j){
            if(!graph[i][j]){
                if(i<xstart || i>=xstart+50 || j<ystart || j>=ystart+100){
                    log->getOut()<<' ';
                    std::cout<<' ';
                } else {
                    log->getOut()<<'x';
                    std::cout<<'x';
                }
            }else{
                std::cout<<graph[i][j];
                log->getOut()<<graph[i][j];
            }
        }
        std::cout<<'|'<<std::endl;
        log->getOut()<<"|\n";
    }
    for(int i=0;i<122;++i){
        std::cout<<'-';
        log->getOut()<<'-';
    }
    std::cout<<std::endl;
    log->getOut()<<"\n";
}

void Loop::healCheck(){
    log->debug("母舰恢复检查");
    for(auto &le: allLivingEntity){
        shared_ptr<LivingEntity>ptr_le = le.second;
        if(ptr_le->getNowHealth() == ptr_le->getMaxHealth()){
            continue;
        }
        shared_ptr<Player> p = ptr_le->getPlayer();
        if(!p->isAllowHeal()){
            continue;
        }
        shared_ptr<Carrier> c = p->getCarrier();
        if(ptr_le->getDistance(*c) <= 2*c->getRadius()){
            if(p->subPower(ptr_le->getHealPower())){
                ptr_le->heal(ptr_le->getHealRate());
            }
        }
    }
}

void Loop::buildFinishedCheck(){
    log->debug("建造完毕检查");
    for(auto &p: game->getPlayers()){
        if(p.second->isBuildFinished()){
            p.second->buildCompletely();
        }
    }
}

void Loop::collectFinishedCheck(){
    log->debug("收集完毕检查");
    for(auto &le: allLivingEntity){
        if(le.second->getClassName() != "Fighter"){
            continue;
        }
        shared_ptr<Fighter> f = dynamic_pointer_cast<Fighter>(le.second);
        if(f->collectFinished()){
            f->collectCompletely();
        }
    }
}

bool Loop::hasPlayerWin(){
    bool flag = false;
    shared_ptr<Player> last = nullptr;
    for(auto &p: game->getPlayers()){
        if(p.second->isLost()){
            continue;
        }
        if(!p.second->getCarrier()->isDeath()){
            if(flag) return false;
            else{
                flag = true;
                last = p.second;
                continue;
            }
        }
        for(auto &b: p.second->getBombers()){
            if(!b.second->isDeath()){
                if(flag) return false;
                else{
                    flag = true;
                    last = p.second;
                    continue;
                }
            }
        }
        for(auto &f: p.second->getFighters()){
            if(!f.second->isDeath()){
                if(flag) return false;
                else{
                    flag = true;
                    last = p.second;
                    continue;
                }
            }
        }
        p.second->lose();
    }
    if(last == nullptr){
        endWithTimeOut();
    }else{
        last->win();
        endWithWinner(last);
    }
    return true;
}

map<shared_ptr<LivingEntity>, set<shared_ptr<Entity>>> Loop::sightsOperate(){
    log->debug("视野判断");
    map<shared_ptr<LivingEntity>, set<shared_ptr<Entity>>> sights;
    for(auto &le: allLivingEntity){
        set<shared_ptr<Entity>> thissights;
        for(auto &le2: allLivingEntity){
            if(le==le2) continue;
            if(le.second->getPlayer() == le2.second->getPlayer()) continue;
            if(le.second->isInSight(*le2.second)){
                thissights.insert(le2.second);
            }
        }
        for(auto &b: allBullet){
            if(le.second->isInSight(*b.second)){
                thissights.insert(b.second);
            }
        }
        for(auto &re: allResourceEntity){
            if(le.second->isInSight(*re.second)){
                thissights.insert(re.second);
            }
        }
        sights.insert(make_pair(le.second, thissights));
    }
    return sights;
}

void Loop::run() {
    log->debug("主循环开始");
    while(nowTick < maxTickAllowed) {
        ++nowTick;
        log->debug("现在tick：", nowTick);
        nowTickStartTime = steady_clock::now();
        //读入数据
        judger->read(duration_cast<milliseconds>(nowTickEndTime.time_since_epoch()).count());
        //生成资源实体
        game->getResourceGenerator()->generate(allResourceEntity.size());
        //运动
        moveNextTick();
        //边界检测：出界的实体强制设定在界内最近点
        edgeCheckForLivingEntity();
        //边界检测：出界的子弹删除
        edgeCheckForBullet();
        //碰撞检测：任何实体和资源实体都不会相撞
        //碰撞检测：活实体撞活实体，必定至少有一个gg，另一个掉这么多血
        impactCheckForLivingEntityAndLivingEntity();
        //碰撞检测：子弹碰子弹，子弹消失
        impactCheckForBulletAndBullet();
        //碰撞检测：子弹碰活实体，子弹消失，活实体受伤害
        impactCheckForBulletAndLivingEntity();
        //母舰恢复检测
        healCheck();
        //建造完毕判断
        buildFinishedCheck();
        //采集完毕判断
        collectFinishedCheck();
        //临时显示
        showInText();
        //视野判断
        map<shared_ptr<LivingEntity>, set<shared_ptr<Entity>>> sights = sightsOperate();
        //数据写出
        judger->dataWrite(sights);
        //判断胜利
        if(hasPlayerWin())return;
        //休眠机制（确保最小tick的执行时间为timePerTick）
        duration<double> time_span = duration_cast<duration<double>>(steady_clock::now() - nowTickStartTime);
        milliseconds deltatime = duration_cast<milliseconds>(time_span);
        if(deltatime < timePerTick){
           sleep_for(timePerTick - deltatime);
        }
        nowTickEndTime = steady_clock::now();
        log->debug("tick结束");
    }
    endWithTimeOut();
}

void Loop::init() {
    log->debug("主循环初始化");
    nowTick = 0;

}

void Loop::endWithWinner(shared_ptr<Player> const winner) {
    log->information("游戏结束！");
    log->debug("存在玩家胜利的游戏结束");
    winner->win();
}

void Loop::endWithTimeOut() {
    log->information("游戏结束！");
    log->debug("时间用尽的游戏结束");
}

long Loop::getMaxTickAllowed() const {
    return maxTickAllowed;
}

void Loop::addResourceEntity(shared_ptr<ResourceEntity> const entity){
    log->debug("添加资源实体");
    for(auto &re: allResourceEntity){
        if(re.second->isOverlapped(*entity) || re.second->contains(*entity) || re.second->isContained(*entity)){
            return;
        }
    }
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

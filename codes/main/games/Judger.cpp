/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Judger.h"
#include "../systems/Engine.h"
#include <QMessageBox>
#include "../../ui/uitest.h"
#define log Engine::getInstance()->getLogger()
#define game Engine::getInstance()->getNowGame()
#define loop Engine::getInstance()->getNowGame()->getLoop()
#define mapp Engine::getInstance()->getNowGame()->getMap()
using std::chrono::duration, std::chrono::duration_cast;

queue<string> Judger::jsons = queue<string>();

/**
 * Judger implementation
 */

Judger::Judger(shared_ptr<JudgerConfiguration> const config){
    log->debug("构造裁判对象");
    maxTimeout = config->getMaxTimeout();
}

void Judger::init(){
    log->debug("裁判初始化");
}

//TODO: 消息队列的对接处理
void Judger::read(const long allowTime){
    log->debug("允许的时间戳", allowTime);
    set<string> uids;
    begin:
    while(jsons.empty()){
        log->debug("等待数据接入中...");
        std::this_thread::sleep_for(milliseconds(5000));
    }
    string json = jsons.front();
    jsons.pop();
    if(!readJson(json.c_str(), allowTime, uids)){
        goto begin;
    }else if(uids.size() < game->getPlayerNumber()){
        goto begin;
    }
}

bool Judger::readJson(const char* json, const long allowTime, set<string>& uids){
    log->debug(json);
    Document document;
    document.Parse(json);
    log->debug("1");
    if(!checkTimestamp(document, allowTime)){
        return false;
    }
    log->debug("2");
    Value::ConstMemberIterator playerData = document.FindMember("player_data");
    if(!(playerData != document.MemberEnd() && playerData->value.IsObject())){
        return false;
    }
    const Value& data = playerData->value;
    log->debug("3");
    Value::ConstMemberIterator uid = document.FindMember("uid");
    if(uid == document.MemberEnd() || !uid->value.IsString()){
        return false;
    }
    if(uids.find(uid->value.GetString())!=uids.end()) return false;
    log->debug("4");
    shared_ptr<Player> player = game->getPlayer(uid->value.GetString());
    Value::ConstMemberIterator build = data.FindMember("build");
    if(build != data.MemberEnd() && data.IsBool()){
        player->build();
    }
    log->debug("5");
    Value::ConstMemberIterator allowHeal = playerData->value.FindMember("allow_heal");
    if(allowHeal != data.MemberEnd() && allowHeal->value.IsBool()){
        player->setAllowHeal(allowHeal->value.GetBool());
    }
    log->debug("6");
    Value::ConstMemberIterator car = playerData->value.FindMember("carrier");
    if(car != data.MemberEnd() && car->value.IsObject()){
        const Value& carrier = car->value;
        readCarrierJson(carrier, player->getCarrier());
    }
    log->debug("7");
    Value::ConstMemberIterator bob = playerData->value.FindMember("bomber");
    if(bob != data.MemberEnd() && bob->value.IsArray()){
        for(auto &i: bob->value.GetArray()){
            Value::ConstMemberIterator buid = i.FindMember("uid");
            if(buid != i.MemberEnd() && buid->value.IsInt()){
                const shared_ptr<Bomber> &p = player->getBomber(buid->value.GetInt());
                if(p == nullptr) continue;
                readBomberJson(i, p);
            }
        }
    }
    log->debug("8");
    Value::ConstMemberIterator fgt = playerData->value.FindMember("fighter");
    if(fgt != data.MemberEnd() && fgt->value.IsArray()){
        for(auto &i: fgt->value.GetArray()){
            Value::ConstMemberIterator fuid = i.FindMember("uid");
            if(fuid != i.MemberEnd() && fuid->value.IsInt()){
                const shared_ptr<Fighter> &p = player->getFighter(fuid->value.GetInt());
                if(p == nullptr) continue;
                readFighterJson(i, p);
            }
        }
    }
    uids.insert(uid->value.GetString());
    return true;
}

void Judger::readFighterJson(const Value& root, const shared_ptr<Fighter>& fighter){
    Value::ConstMemberIterator move = root.FindMember("move");
    if(move != root.MemberEnd() && move->value.IsBool()){
        fighter->setMoving(move->value.GetBool());
        fighter->stopCollecting();
    }
    Value::ConstMemberIterator turn = root.FindMember("turn_direction");
    if(turn != root.MemberEnd() && turn->value.IsDouble()){
        fighter->turnDirection(turn->value.GetDouble());
    }
    Value::ConstMemberIterator use_weapon = root.FindMember("use_weapon");
    if(use_weapon != root.MemberEnd() && use_weapon->value.IsBool()){
        if(use_weapon->value.GetBool()){
            Value::ConstMemberIterator direction = root.FindMember("weapon_shoot_direction");
            if(direction != root.MemberEnd() && direction->value.IsDouble()){
                fighter->shoot(direction->value.GetDouble());
            }
        }
    }
    Value::ConstMemberIterator collecting = root.FindMember("collecting");
    if(collecting != root.MemberEnd() && collecting->value.IsBool()){
        Value::ConstMemberIterator collect_id = root.FindMember("collect_entity_uid");
        if(collect_id != root.MemberEnd() && collect_id->value.IsInt()){
            const shared_ptr<ResourceEntity>& p = loop->findResourceEntity(collect_id->value.GetInt());
            if(p != nullptr){
                fighter->collect(p);
            }
        }
    }
}

void Judger::readBomberJson(const Value& root, const shared_ptr<Bomber>& bomber){
    Value::ConstMemberIterator move = root.FindMember("move");
    if(move != root.MemberEnd() && move->value.IsBool()){
        bomber->setMoving(move->value.GetBool());
    }
    Value::ConstMemberIterator turn = root.FindMember("turn_direction");
    if(turn != root.MemberEnd() && turn->value.IsDouble()){
        bomber->turnDirection(turn->value.GetDouble());
    }
    Value::ConstMemberIterator use_weapon = root.FindMember("use_weapon");
    if(use_weapon != root.MemberEnd() && use_weapon->value.IsBool()){
        if(use_weapon->value.GetBool()){
            Value::ConstMemberIterator direction = root.FindMember("weapon_shoot_direction");
            if(direction != root.MemberEnd() && direction->value.IsDouble()){
                bomber->shoot(direction->value.GetDouble());
            }
        }
    }
}

void Judger::readCarrierJson(const Value& root, const shared_ptr<Carrier>& carrier){
    Value::ConstMemberIterator uid = root.FindMember("uid");
    if(uid != root.MemberEnd() && uid->value.IsInt()){
        if(uid->value.GetInt() != carrier->getUID()) return;
    }
    Value::ConstMemberIterator move = root.FindMember("move");
    if(move != root.MemberEnd() && move->value.IsBool()){
        carrier->setMoving(move->value.GetBool());
    }
    Value::ConstMemberIterator turn = root.FindMember("turn_direction");
    if(turn != root.MemberEnd() && turn->value.IsDouble()){
        carrier->turnDirection(turn->value.GetDouble());
    }
    Value::ConstMemberIterator use_weapon = root.FindMember("use_weapon");
    if(use_weapon != root.MemberEnd() && use_weapon->value.IsBool()){
        if(use_weapon->value.GetBool()){
            Value::ConstMemberIterator direction = root.FindMember("weapon_shoot_direction");
            if(direction != root.MemberEnd() && direction->value.IsDouble()){
                carrier->shoot(direction->value.GetDouble());
            }
        }
    }
    Value::ConstMemberIterator use_nuke = root.FindMember("use_nuke");
    if(use_nuke != root.MemberEnd() && use_nuke->value.IsBool()){
        if(use_nuke->value.GetBool()){
            Value::ConstMemberIterator direction = root.FindMember("nuke_shoot_direction");
            if(direction != root.MemberEnd() && direction->value.IsDouble()){
                carrier->shoot(direction->value.GetDouble());
            }
        }
    }
}

bool Judger::checkTimestamp(const Document& document, const long& allowTime){
    log->debug("1111");
    Value::ConstMemberIterator time = document.FindMember("time");
    log->debug("11");
    if(time == document.MemberEnd() || !time->value.IsInt64()){
        log->debug("111");
        return false;
    }else{
        return allowTime <= time->value.GetInt64();
    }
}

bool Judger::readStartData(){
    set<string> uids;
    int i=0, index = 0;
    while(uids.size() < game->getPlayerNumber()){
        if(jsons.empty()){
            log->warning("数据池空缺！");
            std::this_thread::sleep_for(milliseconds(1000));
            ++i;
            if(i > 10){
                log->warning("由于长时间未能开始游戏，游戏中止。");
                return false;
            }
            continue;
        }
        string json = jsons.front();
        log->debug(json);
        log->debug("收到预先数据");
        //TODO: 不合法数据会触发异常，catch掉
        jsons.pop();
        Document document;
        document.Parse(json.c_str());
        Value::ConstMemberIterator uid = document.FindMember("uid");
        if(uid == document.MemberEnd() || !uid->value.IsString()) continue;
        Value::ConstMemberIterator name = document.FindMember("name");
        if(name == document.MemberEnd() || !name->value.IsString()) continue;
        Value::ConstMemberIterator a = document.FindMember("color_a");
        if(a == document.MemberEnd() || !a->value.IsInt()) continue;
        Value::ConstMemberIterator r = document.FindMember("color_r");
        if(r == document.MemberEnd() || !r->value.IsInt()) continue;
        Value::ConstMemberIterator g = document.FindMember("color_g");
        if(g == document.MemberEnd() || !g->value.IsInt()) continue;
        Value::ConstMemberIterator b = document.FindMember("color_b");
        if(b == document.MemberEnd() || !b->value.IsInt()) continue;
        game->tmp_players[index++]->init(uid->value.GetString(), name->value.GetString(),
                                         Color(a->value.GetInt(), r->value.GetInt(), g->value.GetInt(), b->value.GetInt()),
                                         mapp->getBrithPoint());
        uids.insert(uid->value.GetString());
    }
    return true;
}
void Judger::dataWrite(map<shared_ptr<LivingEntity>, set<shared_ptr<Entity>>> sights){
    //TODO: 不合法数据会触发异常，catch掉
    map<string, string> results;
    for(auto &p: game->getPlayers()){
        StringBuffer strBuf;
        Writer<rapidjson::StringBuffer> writer(strBuf);
        writer.StartObject();
        writer.Key("time");
        writer.Int64(duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count());
        writer.Key("tick");
        writer.Int64(loop->getNowTick());
        writer.Key("uid");
        writer.String(p.second->getUID().c_str());
        writer.Key("player_data");
        writer.StartObject();
        writer.Key("power");
        writer.Int(p.second->getPower());
        writer.Key("build");
        writer.Bool(p.second->getBuilding());
        writer.Key("remain_time");
        writer.Int(p.second->getRemainBuildTick());
        writer.Key("carrier");
        writer.StartObject();
        writer.Key("move");
        writer.Bool(p.second->getCarrier()->isMoving());
        writer.Key("direction");
        writer.Double(p.second->getCarrier()->getSpeed().getAbsolutionAngle());
        writer.Key("health");
        writer.Int(p.second->getCarrier()->getNowHealth());
        writer.Key("x");
        writer.Double(p.second->getCarrier()->getX());
        writer.Key("y");
        writer.Double(p.second->getCarrier()->getY());
        writer.Key("weapon_cd");
        writer.Int(p.second->getCarrier()->getWeaponCD());
        writer.Key("used_nuke");
        writer.Bool(p.second->getCarrier()->getNukeShooted());
        writer.Key("sights");
        writer.StartArray();
        for(auto &e: sights.find(p.second->getCarrier())->second){
            writer.StartObject();
            writer.Key("uid");
            writer.Int(e->getUID());
            writer.Key("type");
            writer.String(e->getClassName().c_str());
            writer.Key("abs_direction");
            writer.Double(Vector2D(p.second->getCarrier()->getPoint(), e->getPoint()).getAbsolutionAngle());
            writer.Key("distance");
            writer.Double(p.second->getCarrier()->getDistance(*e));
            writer.EndObject();
        }
        writer.EndArray();
        writer.EndObject();
        writer.Key("bomber");
        writer.StartArray();
        for(auto &b: p.second->getBombers()){
            writer.StartObject();
            writer.Key("move");
            writer.Bool(b.second->isMoving());
            writer.Key("direction");
            writer.Double(b.second->getSpeed().getAbsolutionAngle());
            writer.Key("health");
            writer.Int(b.second->getNowHealth());
            writer.Key("x");
            writer.Double(b.second->getX());
            writer.Key("y");
            writer.Double(b.second->getY());
            writer.Key("weapon_cd");
            writer.Int(b.second->getWeaponCD());
            writer.Key("sights");
            writer.StartArray();
            for(auto &e: sights.find(b.second)->second){
                writer.StartObject();
                writer.Key("uid");
                writer.Int(e->getUID());
                writer.Key("type");
                writer.String(e->getClassName().c_str());
                writer.Key("abs_direction");
                writer.Double(Vector2D(b.second->getPoint(), e->getPoint()).getAbsolutionAngle());
                writer.Key("distance");
                writer.Double(b.second->getDistance(*e));
                if(e->getClassName() == "LittleStarEntity" || e->getClassName() == "LargeStarEntity"){
                    writer.Key("isBeingCollected");
                    writer.Bool(std::dynamic_pointer_cast<ResourceEntity>(e)->isBeingCollected());
                }else if(e->getClassName() == "Bullet"){
                    writer.Key("move_direction");
                    writer.Double(std::dynamic_pointer_cast<Bullet>(e)->getSpeed().getAbsolutionAngle());
                }else if(e->getClassName() =="Bomber" || e->getClassName() =="Fighter"){
                    writer.Key("move");
                    writer.Bool(std::dynamic_pointer_cast<LivingEntity>(e)->isMoving());
                    writer.Key("move_direction");
                    writer.Double(std::dynamic_pointer_cast<LivingEntity>(e)->getSpeed().getAbsolutionAngle());
                }else if(e->getClassName() =="Fighter"){
                    writer.Key("move");
                    writer.Bool(std::dynamic_pointer_cast<LivingEntity>(e)->isMoving());
                    writer.Key("move_direction");
                    writer.Double(std::dynamic_pointer_cast<LivingEntity>(e)->getSpeed().getAbsolutionAngle());
                    writer.Key("collecting");
                    writer.Bool(std::dynamic_pointer_cast<Fighter>(e)->isCollecting());
                }
                writer.EndObject();
            }
            writer.EndArray();
            writer.EndObject();
        }
        writer.EndArray();
        writer.Key("bomber");
        writer.StartArray();
        for(auto &b: p.second->getBombers()){
            writer.StartObject();
            writer.Key("move");
            writer.Bool(b.second->isMoving());
            writer.Key("direction");
            writer.Double(b.second->getSpeed().getAbsolutionAngle());
            writer.Key("health");
            writer.Int(b.second->getNowHealth());
            writer.Key("x");
            writer.Double(b.second->getX());
            writer.Key("y");
            writer.Double(b.second->getY());
            writer.Key("weapon_cd");
            writer.Int(b.second->getWeaponCD());
            writer.Key("sights");
            writer.StartArray();
            for(auto &e: sights.find(b.second)->second){
                writer.StartObject();
                writer.Key("uid");
                writer.Int(e->getUID());
                writer.Key("type");
                writer.String(e->getClassName().c_str());
                writer.Key("abs_direction");
                writer.Double(Vector2D(b.second->getPoint(), e->getPoint()).getAbsolutionAngle());
                writer.Key("distance");
                writer.Double(b.second->getDistance(*e));
                if(e->getClassName() == "LittleStarEntity" || e->getClassName() == "LargeStarEntity"){
                    writer.Key("isBeingCollected");
                    writer.Bool(std::dynamic_pointer_cast<ResourceEntity>(e)->isBeingCollected());
                }else if(e->getClassName() == "Bullet"){
                    writer.Key("move_direction");
                    writer.Double(std::dynamic_pointer_cast<Bullet>(e)->getSpeed().getAbsolutionAngle());
                }else if(e->getClassName() =="Bomber" || e->getClassName() =="Fighter"){
                    writer.Key("move");
                    writer.Bool(std::dynamic_pointer_cast<LivingEntity>(e)->isMoving());
                    writer.Key("move_direction");
                    writer.Double(std::dynamic_pointer_cast<LivingEntity>(e)->getSpeed().getAbsolutionAngle());
                }else if(e->getClassName() =="Fighter"){
                    writer.Key("move");
                    writer.Bool(std::dynamic_pointer_cast<LivingEntity>(e)->isMoving());
                    writer.Key("move_direction");
                    writer.Double(std::dynamic_pointer_cast<LivingEntity>(e)->getSpeed().getAbsolutionAngle());
                    writer.Key("collecting");
                    writer.Bool(std::dynamic_pointer_cast<Fighter>(e)->isCollecting());
                }
                writer.EndObject();
            }
            writer.EndArray();
            writer.EndObject();
        }
        writer.EndArray();
        writer.Key("fighter");
        writer.StartArray();
        for(auto &f: p.second->getFighters()){
            writer.StartObject();
            writer.Key("move");
            writer.Bool(f.second->isMoving());
            writer.Key("direction");
            writer.Double(f.second->getSpeed().getAbsolutionAngle());
            writer.Key("health");
            writer.Int(f.second->getNowHealth());
            writer.Key("x");
            writer.Double(f.second->getX());
            writer.Key("y");
            writer.Double(f.second->getY());
            writer.Key("collecting");
            writer.Bool(f.second->isCollecting());
            writer.Key("remain_time");
            writer.Int(f.second->getRemainTime());
            writer.Key("weapon_cd");
            writer.Int(f.second->getWeaponCD());
            writer.Key("sights");
            writer.StartArray();
            for(auto &e: sights.find(f.second)->second){
                writer.StartObject();
                writer.Key("uid");
                writer.Int(e->getUID());
                writer.Key("type");
                writer.String(e->getClassName().c_str());
                writer.Key("abs_direction");
                writer.Double(Vector2D(f.second->getPoint(), e->getPoint()).getAbsolutionAngle());
                writer.Key("distance");
                writer.Double(f.second->getDistance(*e));
                if(e->getClassName() == "LittleStarEntity" || e->getClassName() == "LargeStarEntity"){
                    writer.Key("isBeingCollected");
                    writer.Bool(std::dynamic_pointer_cast<ResourceEntity>(e)->isBeingCollected());
                }else if(e->getClassName() == "Bullet"){
                    writer.Key("move_direction");
                    writer.Double(std::dynamic_pointer_cast<Bullet>(e)->getSpeed().getAbsolutionAngle());
                }else if(e->getClassName() =="Bomber" || e->getClassName() =="Fighter"){
                    writer.Key("move");
                    writer.Bool(std::dynamic_pointer_cast<LivingEntity>(e)->isMoving());
                    writer.Key("move_direction");
                    writer.Double(std::dynamic_pointer_cast<LivingEntity>(e)->getSpeed().getAbsolutionAngle());
                }else if(e->getClassName() =="Fighter"){
                    writer.Key("move");
                    writer.Bool(std::dynamic_pointer_cast<LivingEntity>(e)->isMoving());
                    writer.Key("move_direction");
                    writer.Double(std::dynamic_pointer_cast<LivingEntity>(e)->getSpeed().getAbsolutionAngle());
                    writer.Key("collecting");
                    writer.Bool(std::dynamic_pointer_cast<Fighter>(e)->isCollecting());
                }
                writer.EndObject();
            }
            writer.EndArray();
            writer.EndObject();
        }
        writer.EndArray();
        writer.EndObject();
        results.insert(make_pair(p.second->getUID(), strBuf.GetString()));
    }
    QString s = "";
    for(auto &i : results){
        s.append(i.first.c_str()).append("\n").append(i.second.c_str()).append("\n");
    }
    emit Engine::getInstance()->getThread()->back(s);
}

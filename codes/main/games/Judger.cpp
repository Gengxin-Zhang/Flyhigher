/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Judger.h"
#include "../systems/Engine.h"
#define log Engine::getInstance()->getLogger()
#define game Engine::getInstance()->getNowGame()
#define loop Engine::getInstance()->getNowGame()->getLoop()

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

}

bool Judger::readJson(const char* json, const long allowTime){
    Document document;
    document.Parse(json);
    if(!checkTimestamp(document, allowTime)){
        return false;
    }
    Value::ConstMemberIterator playerData = document.FindMember("player_data");
    if(!(playerData != document.MemberEnd() && playerData->value.IsObject())){
        return false;
    }
    const Value& data = playerData->value;
    Value::ConstMemberIterator uid = document.FindMember("uid");
    if(uid == document.MemberEnd() || !uid->value.IsString()){ //TODO: 指定类型！
        return false;
    }
    shared_ptr<Player> player = game->getPlayer(uid->value.GetString()); //TODO: 指定类型！
    Value::ConstMemberIterator build = data.FindMember("build");
    if(build != data.MemberEnd() && data.IsBool()){
        player->build();
    }
    Value::ConstMemberIterator car = playerData->value.FindMember("build");
    if(car != data.MemberEnd() && car->value.IsObject()){
        const Value& carrier = car->value;
        readCarrierJson(carrier, player->getCarrier());
    }
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
    Value::ConstMemberIterator time = document.FindMember("time");
    if(!(time == document.MemberEnd() && time->value.IsInt64())){
        return false;
    }else{
        return allowTime <= time->value.GetInt64();
    }
}

//TODO: 传出数据
//TODO: UID类型
map<string, const char*> Judger::write() const{

}

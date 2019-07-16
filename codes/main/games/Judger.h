/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _JUDGER_H
#define _JUDGER_H

#include "../configs/JudgerConfiguration.h"
#include <memory>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "./entitys/Carrier.h"
#include "./entitys/Bomber.h"
#include "./entitys/Fighter.h"
#include <map>
using namespace rapidjson;
using std::shared_ptr, std::map;

class Judger {
    public:
        Judger(shared_ptr<JudgerConfiguration> const config);
        void init();
        void read(const long allowTime);
        //TODO: UID类型
        map<string, const char*> write() const;
    private:
        void readFighterJson(const Value& root, const shared_ptr<Fighter>& fighter);
        void readCarrierJson(const Value& root, const shared_ptr<Carrier>& carrier);
        void readBomberJson(const Value& root, const shared_ptr<Bomber>& bomber);
        bool readJson(const char* json, const long allowTime);
        bool checkTimestamp(const Document& document, const long& allowTime);
        int maxTimeout;
};

#endif //_JUDGER_H

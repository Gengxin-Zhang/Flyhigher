/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _JUDGER_H
#define _JUDGER_H

#include "../configs/JudgerConfiguration.h"
#include <memory>
using std::shared_ptr;

class Engine;
class Logger;

class Judger {
    public:
        Judger(shared_ptr<JudgerConfiguration> const config);
        void init();
    private:
};

#endif //_JUDGER_H

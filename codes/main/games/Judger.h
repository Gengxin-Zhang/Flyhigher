/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _JUDGER_H
#define _JUDGER_H

#include "../configs/JudgerConfiguration.h"

class Engine;
class Logger;

class Judger {
    public:
        Judger(JudgerConfiguration * const config);
        void init();
    private:
};

#endif //_JUDGER_H

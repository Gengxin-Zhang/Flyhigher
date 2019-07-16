/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Judger.h"
#include "../systems/Engine.h"
#define log Engine::getInstance()->getLogger()

/**
 * Judger implementation
 */

Judger::Judger(shared_ptr<JudgerConfiguration> const config){
    log->debug("构造裁判对象");
}

void Judger::init(){
    log->debug("裁判初始化");
}

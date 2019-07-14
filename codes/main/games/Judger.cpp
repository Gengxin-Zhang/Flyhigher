/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Judger.h"
#include "../../tools/Logger.h"
#include "../systems/Engine.h"

/**
 * Judger implementation
 */

Judger::Judger(JudgerConfiguration* const config){
    Logger* logger = Engine::getInstance()->getLogger();
    logger->debug("构造裁判对象");
}

void Judger::init(){
    Logger* logger = Engine::getInstance()->getLogger();
    logger->debug("裁判初始化");
}

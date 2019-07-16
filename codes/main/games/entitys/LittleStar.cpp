/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "LittleStar.h"

/**
 * LittleStar implementation
 * 
 * 小型资源行星
 */

LittleStar::LittleStar(shared_ptr<LittleStarConfiguration> const config, double x, double y):
    ResourceEntity (config->getRadius(), config->getPower(), config->getCollectTick(), nullptr, x, y){
    //TODO: 通过配置项调用父类构造函数
}

LittleStar::~LittleStar() {

}

string LittleStar::getClassName() const{
    return "LittleStar";
}

string LittleStar::toString() const{
    return ResourceEntity::toString() +"  [LittleStar] ()";
}

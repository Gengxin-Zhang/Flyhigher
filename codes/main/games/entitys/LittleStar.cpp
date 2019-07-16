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

LittleStar::LittleStar(shared_ptr<LittleStarConfiguration> const config):
    ResourceEntity (config->getRadius(), config->getPower()){
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

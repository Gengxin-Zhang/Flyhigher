/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "LargeStar.h"

/**
 * LargeStar implementation
 * 
 * 大型资源行星
 */

LargeStar::LargeStar(shared_ptr<LargeStarConfiguration> const config):
    ResourceEntity (config->getRadius(), config->getPower()){
    //TODO: 通过配置项调用父类构造函数
}

LargeStar::~LargeStar() {

}

string LargeStar::getClassName() const{
    return "LargeStar";
}

string LargeStar::toString() const{
    return ResourceEntity::toString() +"[LargeStar] ()";
}

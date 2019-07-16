/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Map.h"
#include "../systems/Engine.h"
#define log Engine::getInstance()->getLogger()
using std::to_string;

/**
 * Map implementation
 */

Map::Map(shared_ptr<MapConfiguration> const config){
    log->debug("构造地图对象");
    height = config->getHeight();
    width = config->getWidth();
    maxPlayersAllowed = config->getMaxPlayer();
    birthPoints = config->getBirthPoints();
}

Map::~Map(){
}

double Map::getHeight() const{
    return height;
}

double Map::getWidth() const{
    return width;
}

bool Map::isEntityInMap(const Entity& entity) const{
    double x = entity.getX();
    double y = entity.getY();
    if(x < 0 || x > width){
        return false;
    }else if( y < 0 || y > height){
        return false;
    }else{
        return true;
    }
}

int Map::getMaxPlayersAllowed() const{
    return maxPlayersAllowed;
}

Point2D Map::getBrithPoint(const int index) const{
    if(index < 0 || index >= maxPlayersAllowed){
        log->severe("获取不存在的地图出生点，值：", index);
        throw invalid_argument("index should not be " + to_string(index));
    }
    return birthPoints[index];
}

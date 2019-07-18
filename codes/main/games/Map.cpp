/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */

#include "Map.h"
#include "../systems/Engine.h"
#include <algorithm>
#include <random>
#define log Engine::getInstance()->getLogger()
using std::to_string, std::shuffle, std::random_device, std::mt19937;

/**
 * Map implementation
 */

int Map::getRandperm(){
    return temp[inx++];
}

Map::Map(shared_ptr<MapConfiguration> const config){
    log->debug("构造地图对象");
    height = config->getHeight();
    width = config->getWidth();
    maxPlayersAllowed = config->getMaxPlayer();
    birthPoints = config->getBirthPoints();
    random_device rd;
    mt19937 g(rd());
    for (int i = 0; i < maxPlayersAllowed; ++i){
        temp.push_back(i + 1);
    }
    inx = 0;
    shuffle(temp.begin(), temp.end(), g);
}

Map::~Map(){
}

int Map::getHeight() const{
    return height;
}

int Map::getWidth() const{
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

Point2D Map::getBrithPoint() const{
    return birthPoints[getRandperm()];
}

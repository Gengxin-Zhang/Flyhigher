/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "MapConfiguration.h"
#include "../../main/systems/Engine.h"
#define log Engine::getInstance()->getLogger()

/**
 * MapConfiguration implementation
 */


MapConfiguration::MapConfiguration(const int height, const int width, const int maxPlayer, Point2D* birthPoints) {
    this->height = height;
    this->width = width;
    this->maxPlayer = maxPlayer;
    this->birthPoints = new Point2D[maxPlayer];
    for(int i = 0; i< maxPlayer; ++i){
        this->birthPoints[i] = Point2D(birthPoints[i]);
        log->debug(this->birthPoints[i].toString());
    }
}

MapConfiguration::~MapConfiguration() {

}

int MapConfiguration::getHeight() const{
    return height;
}

int MapConfiguration::getWidth() const{
    return width;
}

int MapConfiguration::getMaxPlayer() const{
    return maxPlayer;
}

Point2D* MapConfiguration::getBirthPoints() const{
    return birthPoints;
}

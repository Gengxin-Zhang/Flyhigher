/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "MapConfiguration.h"

/**
 * MapConfiguration implementation
 */


MapConfiguration::MapConfiguration(const int height, const int width, const int maxPlayer, const Point2D* birthPoints) {
    this->height = height;
    this->width = width;
    this->maxPlayer = maxPlayer;
    this->birthPoints = birthPoints;
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

const Point2D* MapConfiguration::getBirthPoints() const{
    return birthPoints;
}

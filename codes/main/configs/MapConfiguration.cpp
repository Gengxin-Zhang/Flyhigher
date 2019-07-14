/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "MapConfiguration.h"

/**
 * MapConfiguration implementation
 */


MapConfiguration::MapConfiguration(const double height, const double width, const int maxPlayer, const Point2D* birthPoints) {
    this->height = height;
    this->width = width;
    this->maxPlayer = maxPlayer;
    this->birthPoints = birthPoints;
}

MapConfiguration::~MapConfiguration() {

}

double MapConfiguration::getHeight() const{
    return height;
}

double MapConfiguration::getWidth() const{
    return width;
}

int MapConfiguration::getMaxPlayer() const{
    return maxPlayer;
}

const Point2D* MapConfiguration::getBirthPoints() const{
    return birthPoints;
}

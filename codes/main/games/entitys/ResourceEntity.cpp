/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "ResourceEntity.h"

/**
 * ResourceEntity implementation
 */

ResourceEntity::ResourceEntity(const double radius, const int power,
 Entity* const parentEntity, const double x, const double y) : Entity(radius, parentEntity, x, y) {

}

int ResourceEntity::getPower() const{
    return power;
}

ResourceEntity::~ResourceEntity() {

}

void ResourceEntity::setBeingCollected(const bool being) {
    beingCollected = being;
    
}

bool ResourceEntity::isBeingCollected() const{
    return beingCollected;
}
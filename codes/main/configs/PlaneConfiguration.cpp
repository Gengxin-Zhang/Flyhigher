/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "PlaneConfiguration.h"

/**
 * PlaneConfiguration implementation
 */


int PlaneConfiguration::getMaxHealth() const{
    return maxHealth;
}

double PlaneConfiguration::getSpeed() const{
    return speed;
}

double PlaneConfiguration::getRadius() const{
    return radius;
}

int PlaneConfiguration::getHealRate() const{
    return healRate;
}

int PlaneConfiguration::getHealPower() const{
    return healPower;
}

PlaneConfiguration::PlaneConfiguration(const int maxHealth, const double speed, const double radius,
 const int healRate, const int healPower) {
    this->maxHealth = maxHealth;
    this->speed = speed;
    this->radius =radius;
    this->healRate = healRate;
    this->healPower = healPower;
}

PlaneConfiguration::~PlaneConfiguration() {

}

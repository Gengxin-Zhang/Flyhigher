/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Bullet.h"

/**
 * Bullet implementation
 */

Bullet::Bullet(const double radius, const Vector2D speed, const int damage,
 Entity* const parentEntity, const double x, const double y): MovableEntity(radius, speed, parentEntity, x, y) {
     this->damage = damage;
}

int Bullet::getDamage() const{
    return damage;
}

void Bullet::damageTo(LivingEntity& entity) const{
    entity.damage(damage);
}

Bullet::~Bullet() {

}
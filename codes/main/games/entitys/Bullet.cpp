/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Bullet.h"
#include "../../systems/Engine.h"
using std::to_string;
#define log Engine::getInstance()->getLogger()
/**
 * Bullet implementation
 */

Bullet::Bullet(const double radius, const Vector2D speed, const int damage,
 shared_ptr<Entity> const parentEntity, const double x, const double y): MovableEntity(radius, speed, parentEntity, x, y) {
     this->damage = damage;
}

int Bullet::getDamage() const{
    return damage;
}

bool Bullet::damageTo(LivingEntity& entity) const{
    return entity.damage(damage);
}

Bullet::~Bullet() {

}

Damageable::~Damageable(){

}

string Bullet::getClassName() const{
    return "Bullet";
}

string Bullet::toString() const{
    return MovableEntity::toString() + "[Bullet] (damage="+ to_string(damage) +")";
}

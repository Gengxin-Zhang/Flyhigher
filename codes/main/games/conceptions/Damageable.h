/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _DAMAGEABLE_H
#define _DAMAGEABLE_H

class Damageable {
public: 
    
/**
 * 对一个实体造成伤害
 * @param victim
 */
virtual void damageTo(LivingEntity victim) = 0;
};

#endif //_DAMAGEABLE_H
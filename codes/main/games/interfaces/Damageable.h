/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _DAMAGEABLE_H
#define _DAMAGEABLE_H

#include "../entitys/LivingEntity.h"

class Damageable {
    public:
        /**
         * 对一个实体造成伤害
         * @param victim
         * @return 实体是否死亡
         */
        virtual bool damageTo(LivingEntity& victim) const = 0;

        /**
         * 虚析构函数
         */
        virtual ~Damageable();
};

#endif //_DAMAGEABLE_H

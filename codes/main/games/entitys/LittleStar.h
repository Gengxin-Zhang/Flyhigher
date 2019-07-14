/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _LITTLESTAR_H
#define _LITTLESTAR_H

#include "ResourceEntity.h"
#include "../../configs/LittleStarConfiguration.h"


class LittleStar: public ResourceEntity {
    public:  
        /**
         * 构造函数
         * @param config 配置项
         */
        LittleStar(LittleStarConfiguration* const config);
            
        /**
         * 析构函数
         */
        ~LittleStar();
};


#endif //_LITTLESTAR_H

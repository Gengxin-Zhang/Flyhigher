/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _LARGESTAR_H
#define _LARGESTAR_H

#include "ResourceEntity.h"
#include "../../configs/LargeStarConfiguration.h"


class LargeStar: public ResourceEntity {
    public: 
        /**
         * 构造函数
         * @param config
         */
        LargeStar(LargeStarConfiguration* const config);
            
        /**
         * 析构函数
         */
        ~LargeStar();
};

#endif //_LARGESTAR_H

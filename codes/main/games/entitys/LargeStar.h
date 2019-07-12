/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _LARGESTAR_H
#define _LARGESTAR_H

#include "ResourceEntity.h"


class LargeStar: public ResourceEntity {
    public: 
        /**
         * 构造函数
         * @param config
         */
        LargeStar(const LargeStarConfiguration& config);
            
        /**
         * 析构函数
         */
        ~LargeStar();
    private:
        //大型资源行星配置项
        LargeStarConfiguration config;
};

#endif //_LARGESTAR_H
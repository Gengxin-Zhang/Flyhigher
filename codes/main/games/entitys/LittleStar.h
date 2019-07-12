/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _LITTLESTAR_H
#define _LITTLESTAR_H

#include "ResourceEntity.h"


class LittleStar: public ResourceEntity {
    public:  
        /**
         * 构造函数
         * @param config 配置项
         */
        LittleStar(const LittleStarConfiguration& config);
            
        /**
         * 析构函数
         */
        ~LittleStar();
    private: 
        //小型资源行星配置项
        LittleStarConfiguration config;
};


#endif //_LITTLESTAR_H
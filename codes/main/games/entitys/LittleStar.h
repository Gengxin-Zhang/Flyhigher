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
 * 小型资源行星配置项
 */
LittleStarConfiguration config;
    
/**
 * 构造函数
 * @param config
 */
void LittleStar(LittleStarConfiguration config);
    
/**
 * 析构函数
 */
void ~LittleStar();
};

#endif //_LITTLESTAR_H
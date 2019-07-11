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
 * 大型资源行星配置项
 */
LargeStarConfiguration config;
    
/**
 * 构造函数
 * @param config
 */
void LargeStar(LargeStarConfiguration config);
    
/**
 * 析构函数
 */
void ~LargeStar();
};

#endif //_LARGESTAR_H
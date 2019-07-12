/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _RESOURCEENTITY_H
#define _RESOURCEENTITY_H

#include "Entity.h"


class ResourceEntity: public Entity {
    public:
        /**
         * 构造函数
         * @param radius 碰撞半径
         * @param power 资源值
         * @param parentEntity 父实体
         * @param x x坐标
         * @param y y坐标
         */
        ResourceEntity(const double radius, const int power, Entity* const parentEntity, const double x, const double y);
            
        /**
         * 获取资源量
         */
        int getPower() const;
            
        /**
         * 析构函数
         */
        ~ResourceEntity();
            
        /**
         * 设置是否被采集
         * @param bool being 是否被采集
         */
        void setBeingCollected(const bool being);
            
        /**
         * 是否正在被采集
         */
        bool isBeingCollected() const;
    private: 
        //这个资源实体具有的资源量
        int power;
        //是否正在被采集
        bool beingCollected;
};

#endif //_RESOURCEENTITY_H
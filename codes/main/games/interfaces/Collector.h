/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _COLLECTOR_H
#define _COLLECTOR_H

#include "../entitys/ResourceEntity.h"

class Collector {
    public:
        /**
         * 是否正在采集
         * @return 是否正在采集
         */
        virtual bool isCollecting() const = 0;

        /**
         * 采集一个资源实体
         * @param entity 实体
         */
        virtual void collect(ResourceEntity& entity) = 0;

        /**
         * 采集完毕
         */
        virtual void collectCompletely() = 0;

        /**
         * 中止采集
         */
        virtual void stopCollecting() = 0;

        /**
         * 虚析构函数
         */
        virtual ~Collector();
};

#endif //_COLLECTOR_H

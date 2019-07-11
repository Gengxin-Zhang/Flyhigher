/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _COLLECTOR_H
#define _COLLECTOR_H

class Collector {
public: 
    
/**
 * 是否正在采集
 * @param
 */
virtual void isCollecting(bool ) = 0;
    
/**
 * 采集一个资源实体
 * @param entity
 */
virtual void collect(ResourceEntity entity) = 0;
    
/**
 * 采集完毕
 */
virtual void collectCompletely() = 0;
    
void stopCollecting();
};

#endif //_COLLECTOR_H
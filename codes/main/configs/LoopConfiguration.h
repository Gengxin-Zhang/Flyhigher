/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _LOOPCONFIGURATION_H
#define _LOOPCONFIGURATION_H

#include <chrono>
using std::chrono::milliseconds;

class LoopConfiguration {
    public:
        /**
         * 获取系统允许的最大ticks
         */
        long getMaxTickAllowed() const;

        /**
         * 获取每tick的小间隔时间
         */
        milliseconds getTimePerTick() const;
        
        /**
         * 构造函数
         * @param maxTickAllowed 系统允许的最大ticks
         * @param timePerTick 每tick允许的最小时间，单位ms
         */
        LoopConfiguration(const long maxTickAllowed, const milliseconds timePerTick);
        
        /**
         * 析构函数
         */
        ~LoopConfiguration();
    private: 
        long maxTickAllowed;
        milliseconds timePerTick;
};

#endif //_LOOPCONFIGURATION_H

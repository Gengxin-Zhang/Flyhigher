/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _LOOPCONFIGURATION_H
#define _LOOPCONFIGURATION_H

class LoopConfiguration {
    public:
        /**
         * 获取系统允许的最大ticks
         */
        long getMaxTickAllowed() const;
        
        /**
         * 构造函数
         * @param maxTickAllowed 系统允许的最大ticks
         */
        LoopConfiguration(const long maxTickAllowed);
        
        /**
         * 析构函数
         */
        ~LoopConfiguration();
    private: 
        long maxTickAllowed;
};

#endif //_LOOPCONFIGURATION_H
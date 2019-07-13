/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _REBUILDABLECONFIGURATION_H
#define _REBUILDABLECONFIGURATION_H

class RebuildableConfiguration {
    public: 
        /**
         * 返回重新建造一个战斗机需要的资源
         * @return 资源需求
         */
        int getPower() const;
            
        /**
         * 返回重新建造一个战斗机需要的时间，单位tick
         * @return 需要的时间
         */
        int getTick() const;

        /**
         * 构造函数
         * @param power 资源需求
         * @param ticks 需要的时间
         */
        RebuildableConfiguration(const int power, const int ticks);
        
        /**
         * 析构函数
         */
        ~RebuildableConfiguration();
    private: 
        int power;
        int ticks;
};

#endif //_REBUILDABLECONFIGURATION_H
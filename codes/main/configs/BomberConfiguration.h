/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _BOMBERCONFIGURATION_H
#define _BOMBERCONFIGURATION_H

#include "WeaponConfiguration.h"
#include "PlaneConfiguration.h"

class BomberConfiguration {
    public:
        /**
         * 构造函数
         * @param weaponConfig 武器配置项
         * @param config 主配置项
         */
        BomberConfiguration(WeaponConfiguration* const weaponConfig, PlaneConfiguration* const config);
        
        /**
         * 析构函数
         */
        ~BomberConfiguration();
        
        /**
         * 获取武器配置项
         * @return 武器配置项
         */
        WeaponConfiguration* getWeaponConfig() const;
        
        /**
         * 获取主配置项
         * @return 主配置项
         */
        PlaneConfiguration* getConfig() const;
private: 
    WeaponConfiguration* weaponConfig;
    PlaneConfiguration* config;
};

#endif //_BOMBERCONFIGURATION_H
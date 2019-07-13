/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _CARRIERCONFIGURATION_H
#define _CARRIERCONFIGURATION_H

#include "NukeConfiguration.h"
#include "PlaneConfiguration.h"
#include "WeaponConfiguration.h"

class CarrierConfiguration {
    public:
        /**
         * 构造函数
         * @param weaponConfig 主武器配置项
         * @param nukeConfig 必杀武器配置项
         * @param config 主配置项 
         */
        CarrierConfiguration(WeaponConfiguration* const weaponConfig,
         NukeConfiguration* const nukeConfig, PlaneConfiguration* const config);
        
        /**
         * 析构函数
         */
        ~CarrierConfiguration();
        
        /**
         * 主武器配置项
         * @return 主武器配置项
         */
        WeaponConfiguration* getWeaponConfig() const;
        
        /**
         * 必杀武器配置项
         * @return 必杀武器配置项
         */
        NukeConfiguration* getNukeConfig() const;
        
        /**
         * 主配置项
         * @return 主配置项
         */
        PlaneConfiguration* getConfig() const;
    private: 
        NukeConfiguration* nukeConfig;
        PlaneConfiguration* config;
        WeaponConfiguration* weaponConfig;
};

#endif //_CARRIERCONFIGURATION_H
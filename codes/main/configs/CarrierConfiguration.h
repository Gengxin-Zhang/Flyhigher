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
#include <memory>
using std::shared_ptr;

class CarrierConfiguration {
    public:
        /**
         * 构造函数
         * @param weaponConfig 主武器配置项
         * @param nukeConfig 必杀武器配置项
         * @param config 主配置项 
         */
        CarrierConfiguration(shared_ptr<WeaponConfiguration> const weaponConfig,
         shared_ptr<NukeConfiguration> const nukeConfig, shared_ptr<PlaneConfiguration> const config);
        
        /**
         * 析构函数
         */
        ~CarrierConfiguration();
        
        /**
         * 主武器配置项
         * @return 主武器配置项
         */
        shared_ptr<WeaponConfiguration> getWeaponConfig() const;
        
        /**
         * 必杀武器配置项
         * @return 必杀武器配置项
         */
        shared_ptr<NukeConfiguration> getNukeConfig() const;
        
        /**
         * 主配置项
         * @return 主配置项
         */
        shared_ptr<PlaneConfiguration> getConfig() const;
    private: 
        shared_ptr<NukeConfiguration> nukeConfig;
        shared_ptr<PlaneConfiguration> config;
        shared_ptr<WeaponConfiguration> weaponConfig;
};

#endif //_CARRIERCONFIGURATION_H

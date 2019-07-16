/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _BOMBERCONFIGURATION_H
#define _BOMBERCONFIGURATION_H

#include "WeaponConfiguration.h"
#include "PlaneConfiguration.h"
#include <memory>
using std::shared_ptr;

class BomberConfiguration {
    public:
        /**
         * 构造函数
         * @param weaponConfig 武器配置项
         * @param config 主配置项
         */
        BomberConfiguration(shared_ptr<WeaponConfiguration> const weaponConfig,
                            shared_ptr<PlaneConfiguration> const config);
        
        /**
         * 析构函数
         */
        ~BomberConfiguration();
        
        /**
         * 获取武器配置项
         * @return 武器配置项
         */
        shared_ptr<WeaponConfiguration> getWeaponConfig() const;
        
        /**
         * 获取主配置项
         * @return 主配置项
         */
        shared_ptr<PlaneConfiguration> getConfig() const;
private: 
    shared_ptr<WeaponConfiguration> weaponConfig;
    shared_ptr<PlaneConfiguration> config;
};

#endif //_BOMBERCONFIGURATION_H

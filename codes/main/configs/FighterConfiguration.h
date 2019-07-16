/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _FIGHTERCONFIGURATION_H
#define _FIGHTERCONFIGURATION_H

#include "PlaneConfiguration.h"
#include "WeaponConfiguration.h"
#include "RebuildableConfiguration.h"
#include <memory>
using std::shared_ptr;

class FighterConfiguration {
    public:
        /**
         * 构造函数
         * @param weaponConfig 武器配置项
         * @param rebuildConfig 重新制造配置项
         * @param config 主配置项
         */
        FighterConfiguration(shared_ptr<WeaponConfiguration> const weaponConfig,
                             shared_ptr<RebuildableConfiguration> const rebuildConfig,
                             shared_ptr<PlaneConfiguration> const config);

        /**
         * 析构函数
         */
        ~FighterConfiguration();

        /**
         * 获取武器配置项
         */
        shared_ptr<WeaponConfiguration> getWeaponConfig() const;

        /**
         * 获取重新制造配置项
         */
        shared_ptr<RebuildableConfiguration> getRebuildConfig() const;

        /**
         * 获取主配置项
         */
        shared_ptr<PlaneConfiguration> getConfig() const;
    private: 
        shared_ptr<WeaponConfiguration> weaponConfig;
        shared_ptr<RebuildableConfiguration> rebuildConfig;
        shared_ptr<PlaneConfiguration> config;
};

#endif //_FIGHTERCONFIGURATION_H

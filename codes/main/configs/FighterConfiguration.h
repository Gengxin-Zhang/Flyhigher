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

class FighterConfiguration {
    public:
        /**
         * 构造函数
         * @param weaponConfig 武器配置项
         * @param rebuildConfig 重新制造配置项
         * @param config 主配置项
         */
        FighterConfiguration(WeaponConfiguration* const weaponConfig, RebuildableConfiguration* const rebuildConfig,
         PlaneConfiguration* const config);

        /**
         * 析构函数
         */
        ~FighterConfiguration();

        /**
         * 获取武器配置项
         */
        WeaponConfiguration* getWeaponConfig() const;

        /**
         * 获取重新制造配置项
         */
        RebuildableConfiguration* getRebuildConfig() const;

        /**
         * 获取主配置项
         */
        PlaneConfiguration* getConfig() const;
    private: 
        WeaponConfiguration* weaponConfig;
        RebuildableConfiguration* rebuildConfig;
        PlaneConfiguration* config;
};

#endif //_FIGHTERCONFIGURATION_H
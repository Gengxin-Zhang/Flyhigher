/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#ifndef _PLAYERCONFIGURATION_H
#define _PLAYERCONFIGURATION_H

#include <string>
#include "CarrierConfiguration.h"
#include "BomberConfiguration.h"
#include "FighterConfiguration.h"
#include "../../tools/Color.h"

using std::string;

class PlayerConfiguration {
    public: 
        /**
         * 构造函数
         * @param name 名字
         * @param color 颜色
         */
        PlayerConfiguration(const string name, const Color color,
         shared_ptr<CarrierConfiguration> const carrierConfig, shared_ptr<BomberConfiguration> const bomberConfig,
         shared_ptr<FighterConfiguration> const fighterConfig);

        /**
         * 析构函数
         */
        ~PlayerConfiguration();
        
        /**
         * 获取玩家名称
         * @return 玩家名
         */
        string getName() const;
        
        /**
         * 获取玩家颜色
         * @return 颜色
         */
        Color getColor() const;

        /**
         * 获取母舰配置项
         * @return 母舰配置项
         */
        shared_ptr<CarrierConfiguration> getCarrierConfig() const;

        /**
         * 获取轰炸机配置项
         * @return 轰炸机配置项
         */
        shared_ptr<BomberConfiguration> getBomberConfig() const;

        /**
         * 获取战斗机配置项
         * @return 战斗机配置项
         */
        shared_ptr<FighterConfiguration> getFighterConfig() const;
    private: 
        string name;
        Color color;
        shared_ptr<CarrierConfiguration> carrierConfig;
        shared_ptr<BomberConfiguration> bomberConfig;
        shared_ptr<FighterConfiguration> fighterConfig;
};

#endif //_PLAYERCONFIGURATION_H
